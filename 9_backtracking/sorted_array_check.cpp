#include <cassert>
#include <iostream>
#include <vector>

bool isSorted(const std::vector<int>& arr, size_t index) {
    if (index >= arr.size() || index == arr.size() - 1) return true;
    return (arr[index] <= arr[index + 1]) && isSorted(arr, index + 1);
}

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    assert(isSorted(A, 0) == true);

    std::vector<int> B = {1, 5, 671, 1, 6, 3, 2, 0};
    assert(isSorted(B, 0) == false);

    std::vector<int> C = {};
    assert(isSorted(C, 0) == true);

    std::vector<int> D = {42};
    assert(isSorted(D, 0) == true);

    std::cout << "sorted_array_check tests passed.\n";
    return 0;
}
