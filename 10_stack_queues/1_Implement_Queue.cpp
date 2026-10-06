#include <cassert>
#include <iostream>
#include <vector>

class Queue {
private:
    int frontIndex;
    int rearIndex;
    int capacity;
    int currentSize;
    std::vector<int> arr;

public:
    explicit Queue(int cap = 100)
        : frontIndex(0), rearIndex(cap - 1), capacity(cap), currentSize(0), arr(cap) {}

    [[nodiscard]] bool isFull() const { return currentSize == capacity; }
    [[nodiscard]] bool isEmpty() const { return currentSize == 0; }
    [[nodiscard]] int size() const { return currentSize; }

    bool enqueue(int item) {
        if (isFull()) {
            return false;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        currentSize++;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return item;
    }

    [[nodiscard]] int front() const {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    [[nodiscard]] int rear() const {
        if (isEmpty()) return -1;
        return arr[rearIndex];
    }
};

int main() {
    Queue q(3);
    assert(q.isEmpty());
    assert(q.front() == -1);
    assert(q.rear() == -1);

    assert(q.enqueue(10));
    assert(q.enqueue(20));
    assert(q.enqueue(30));
    assert(q.isFull());
    assert(!q.enqueue(40)); // Capacity reached

    assert(q.front() == 10);
    assert(q.rear() == 30);
    assert(q.dequeue() == 10);
    assert(q.front() == 20);

    // Circular wrap around
    assert(q.enqueue(40));
    assert(q.rear() == 40);
    assert(q.dequeue() == 20);
    assert(q.dequeue() == 30);
    assert(q.dequeue() == 40);
    assert(q.isEmpty());
    assert(q.dequeue() == -1); // Underflow

    std::cout << "10_stack_queues 1_Implement_Queue: All tests passed.\n";
    return 0;
}
