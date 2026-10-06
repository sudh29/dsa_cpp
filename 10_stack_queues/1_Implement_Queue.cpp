#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    int frontIndex, rearIndex, capacity, currentSize;
    vector<int> arr;

public:
    Queue(int cap = 100) : frontIndex(0), rearIndex(cap - 1), capacity(cap), currentSize(0), arr(cap) {}

    bool isFull() { return currentSize == capacity; }
    bool isEmpty() { return currentSize == 0; }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        currentSize++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
        return item;
    }

    int front() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    int rear() {
        if (isEmpty()) return -1;
        return arr[rearIndex];
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front: " << q.front() << " | Rear: " << q.rear() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "New Front: " << q.front() << endl;
    return 0;
}
