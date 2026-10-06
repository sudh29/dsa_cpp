#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0;
    int k = left;

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void merge_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> arr = {5, 2, 6, 7, 2, 1, 0, 3};
    if (!arr.empty()) {
        merge_sort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

    std::cout << "Sorted array (Merge Sort): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    assert(std::is_sorted(arr.begin(), arr.end()));
    assert(arr.front() == 0 && arr.back() == 7);
    return 0;
}
