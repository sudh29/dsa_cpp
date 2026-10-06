#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int> &arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(int N, vector<int> &arr) {
    for (int i = (N - 2) / 2; i >= 0; i--) {
        maxHeapify(arr, N, i);
    }
}

int main() {
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    convertMinToMaxHeap(arr.size(), arr);
    cout << "Converted Min Heap to Max Heap: ";
    for (int v : arr) cout << v << " ";
    cout << endl;
    return 0;
}
