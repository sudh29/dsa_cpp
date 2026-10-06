#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(size_t i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(size_t i) {
        size_t n = heap.size();
        while (2 * i + 1 < n) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;
            size_t largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;

            std::swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw std::runtime_error("Heap empty");
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return maxVal;
    }

    int getMax() const {
        if (heap.empty()) throw std::runtime_error("Heap empty");
        return heap[0];
    }

    [[nodiscard]] bool empty() const { return heap.empty(); }
    [[nodiscard]] size_t size() const { return heap.size(); }
};

int main() {
    MaxHeap mh;
    assert(mh.empty());
    assert(mh.size() == 0);

    for (int v : {3, 10, 5, 1, 4, 12}) {
        mh.insert(v);
    }
    assert(mh.size() == 6);
    assert(!mh.empty());
    assert(mh.getMax() == 12);

    assert(mh.extractMax() == 12);
    assert(mh.getMax() == 10);
    assert(mh.size() == 5);

    assert(mh.extractMax() == 10);
    assert(mh.extractMax() == 5);
    assert(mh.extractMax() == 4);
    assert(mh.extractMax() == 3);
    assert(mh.extractMax() == 1);
    assert(mh.empty());

    std::cout << "11_heap max_heap_fundamentals: All tests passed.\n";
    return 0;
}
