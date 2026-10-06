#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void heapify(int arr[], int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void buildHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    }

    void heapSort(int arr[], int n) {
        buildHeap(arr, n);
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    Solution sol;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.heapSort(arr, n);
    cout << "Heap Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
