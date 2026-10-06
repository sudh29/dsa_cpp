#include <iostream>

using namespace std;

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) cur = cur->next;
        cur->next = newNode;
    }

    void deleteNode(int key) {
        Node *temp = head, *prev = nullptr;
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }

    void printList() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.push(5);
    list.printList(); // 5 -> 10 -> 20 -> NULL
    list.deleteNode(10);
    list.printList(); // 5 -> 20 -> NULL
    return 0;
}
