#include <cassert>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class GenericQueue {
private:
    std::deque<T> elements;

public:
    void enqueue(const T &val) { elements.push_back(val); }
    void dequeue() {
        if (elements.empty()) throw std::out_of_range("Queue<>::dequeue(): empty queue");
        elements.pop_front();
    }
    const T& front() const {
        if (elements.empty()) throw std::out_of_range("Queue<>::front(): empty queue");
        return elements.front();
    }
    [[nodiscard]] bool empty() const { return elements.empty(); }
    [[nodiscard]] size_t size() const { return elements.size(); }
};

int main() {
    GenericQueue<int> intQueue;
    assert(intQueue.empty());
    assert(intQueue.size() == 0);

    intQueue.enqueue(100);
    intQueue.enqueue(200);
    intQueue.enqueue(300);
    assert(intQueue.size() == 3);
    assert(!intQueue.empty());
    assert(intQueue.front() == 100);

    intQueue.dequeue();
    assert(intQueue.front() == 200);
    intQueue.dequeue();
    assert(intQueue.front() == 300);
    intQueue.dequeue();
    assert(intQueue.empty());

    bool caught = false;
    try {
        intQueue.dequeue();
    } catch (const std::out_of_range &) {
        caught = true;
    }
    assert(caught);

    std::cout << "10_stack_queues queue_generic: All tests passed.\n";
    return 0;
}
