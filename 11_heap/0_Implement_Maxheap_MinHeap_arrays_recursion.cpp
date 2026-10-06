#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
    static void maxHeapify(vector<int> &arr, int n, int i) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    static void minHeapify(vector<int> &arr, int n, int i) {
        int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest]) smallest = left;
        if (right < n && arr[right] < arr[smallest]) smallest = right;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }

    static void buildMaxHeap(vector<int> &arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
    }

    static void buildMinHeap(vector<int> &arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
    }
};

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    Heap::buildMaxHeap(arr);
    cout << "Max Heap: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    Heap::buildMinHeap(arr);
    cout << "Min Heap: ";
    for (int v : arr) cout << v << " ";
    cout << endl;
    return 0;
}
