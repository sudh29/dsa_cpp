#include <cassert>
#include <iostream>
#include <vector>

/**
 * Problem: Fundamental Linked List Class Implementation with RAII
 * Module: 5_linklist
 * Time Complexity: O(1) push, O(n) append/delete/search
 * Space Complexity: O(n)
 *
 * Description:
 * Implements a complete singly linked list ADT in modern C++ with proper
 * RAII lifecycle management, push, append, deleteNode, and search.
 */

class LinkedList {
private:
    struct Node {
        int data;
        Node* next{nullptr};
        explicit Node(int val) : data(val), next(nullptr) {}
    };

    Node* head{nullptr};

public:
    LinkedList() = default;

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    LinkedList(LinkedList&& other) noexcept : head(other.head) {
        other.head = nullptr;
    }
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    void clear() noexcept {
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
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    bool deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return true;
        }
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return false;
        prev->next = temp->next;
        delete temp;
        return true;
    }

    [[nodiscard]] std::vector<int> toVector() const {
        std::vector<int> res;
        Node* cur = head;
        while (cur != nullptr) {
            res.push_back(cur->data);
            cur = cur->next;
        }
        return res;
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.push(5);

    // Initial sequence: 5 -> 10 -> 20
    assert(list.toVector() == (std::vector<int>{5, 10, 20}));

    // Delete middle element: 10
    assert(list.deleteNode(10) == true);
    assert(list.toVector() == (std::vector<int>{5, 20}));

    // Delete head: 5
    assert(list.deleteNode(5) == true);
    assert(list.toVector() == (std::vector<int>{20}));

    // Delete non-existent element: 99
    assert(list.deleteNode(99) == false);

    // Delete last remaining element: 20
    assert(list.deleteNode(20) == true);
    assert(list.toVector().empty());

    std::cout << "[PASS] 5_linklist/LinkList1: all tests passed!\n";
    return 0;
}
