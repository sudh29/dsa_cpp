#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap empty");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minVal;
    }

    int getMin() const {
        if (heap.empty()) throw runtime_error("Heap empty");
        return heap[0];
    }

    bool empty() const { return heap.empty(); }
    size_t size() const { return heap.size(); }
};

int main() {
    MinHeap mh;
    for (int v : {3, 10, 5, 1, 4, 12}) mh.insert(v);
    cout << "Min element: " << mh.getMin() << endl; // 1
    cout << "Extracted: " << mh.extractMin() << endl; // 1
    cout << "New Min: " << mh.getMin() << endl; // 3
    return 0;
}
