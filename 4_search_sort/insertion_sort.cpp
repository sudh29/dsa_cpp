#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void insertion_sort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value) {
            arr[hole] = arr[hole - 1];
            --hole;
        }
        arr[hole] = value;
    }
}

int main() {
    std::vector<int> arr = {5, 2, 6, 7, 2, 1, 0, 3};
    insertion_sort(arr);

    std::cout << "Sorted array (Insertion Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    assert(std::is_sorted(arr.begin(), arr.end()));
    assert(arr.front() == 0 && arr.back() == 7);
    return 0;
}
