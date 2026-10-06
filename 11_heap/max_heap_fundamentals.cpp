#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int left = 2 * i + 1, right = 2 * i + 2, largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) throw runtime_error("Heap empty");
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    int getMax() const {
        if (heap.empty()) throw runtime_error("Heap empty");
        return heap[0];
    }

    bool empty() const { return heap.empty(); }
    size_t size() const { return heap.size(); }
};

int main() {
    MaxHeap mh;
    for (int v : {3, 10, 5, 1, 4, 12}) mh.insert(v);
    cout << "Max element: " << mh.getMax() << endl; // 12
    cout << "Extracted: " << mh.extractMax() << endl; // 12
    cout << "New Max: " << mh.getMax() << endl; // 10
    return 0;
}
