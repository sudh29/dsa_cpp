#include <iostream>
#include <deque>
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
    bool empty() const { return elements.empty(); }
    size_t size() const { return elements.size(); }
};

int main() {
    GenericQueue<int> intQueue;
    intQueue.enqueue(100);
    intQueue.enqueue(200);
    intQueue.enqueue(300);

    while (!intQueue.empty()) {
        std::cout << intQueue.front() << " ";
        intQueue.dequeue();
    }
    std::cout << std::endl;
    return 0;
}
