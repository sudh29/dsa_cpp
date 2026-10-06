#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class MidStack {
private:
    Node* head;
    Node* mid;
    int count;

public:
    MidStack() : head(nullptr), mid(nullptr), count(0) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->prev = nullptr;
        newNode->next = head;
        count++;

        if (count == 1) {
            mid = newNode;
        } else {
            head->prev = newNode;
            if (count % 2 != 0) {
                mid = mid->prev;
            }
        }
        head = newNode;
    }

    int pop() {
        if (count == 0) return -1;
        Node* temp = head;
        int item = temp->data;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        count--;

        if (count % 2 == 0 && mid != nullptr) {
            mid = mid->next;
        }
        delete temp;
        return item;
    }

    int findMiddle() {
        if (count == 0) return -1;
        return mid->data;
    }
};

int main() {
    MidStack ms;
    ms.push(11);
    ms.push(22);
    ms.push(33);
    ms.push(44);
    ms.push(55);

    cout << "Middle element: " << ms.findMiddle() << endl; // 33
    cout << "Popped: " << ms.pop() << endl;
    cout << "New Middle element: " << ms.findMiddle() << endl; // 33
    return 0;
}
