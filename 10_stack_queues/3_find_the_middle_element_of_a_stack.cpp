#include <cassert>
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    explicit Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class MidStack {
private:
    Node* head;
    Node* mid;
    int count;

public:
    MidStack() : head(nullptr), mid(nullptr), count(0) {}

    ~MidStack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    MidStack(const MidStack &) = delete;
    MidStack &operator=(const MidStack &) = delete;

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
        if (head != nullptr) {
            head->prev = nullptr;
        }
        count--;

        if (count % 2 == 0 && mid != nullptr) {
            mid = mid->next;
        }
        delete temp;
        if (count == 0) {
            mid = nullptr;
        }
        return item;
    }

    [[nodiscard]] int findMiddle() const {
        if (count == 0 || mid == nullptr) return -1;
        return mid->data;
    }

    [[nodiscard]] int size() const {
        return count;
    }

    [[nodiscard]] bool empty() const {
        return count == 0;
    }
};

int main() {
    MidStack ms;
    assert(ms.empty());
    assert(ms.findMiddle() == -1);

    ms.push(11); // count=1, mid=11
    assert(ms.findMiddle() == 11);

    ms.push(22); // count=2, mid=11
    assert(ms.findMiddle() == 11);

    ms.push(33); // count=3, mid=22
    assert(ms.findMiddle() == 22);

    ms.push(44); // count=4, mid=22
    assert(ms.findMiddle() == 22);

    ms.push(55); // count=5, mid=33
    assert(ms.findMiddle() == 33);

    assert(ms.pop() == 55); // count=4, mid moves to 22
    assert(ms.findMiddle() == 22);

    assert(ms.pop() == 44); // count=3, mid=22
    assert(ms.findMiddle() == 22);

    std::cout << "10_stack_queues 3_find_the_middle_element_of_a_stack: All tests passed.\n";
    return 0;
}
