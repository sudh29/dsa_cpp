#include <iostream>
#include <vector>

bool isSorted(const std::vector<int>& arr, size_t index) {
    if (index >= arr.size() - 1) return true;
    return (arr[index] <= arr[index + 1]) && isSorted(arr, index + 1);
}

int main() {
    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    std::cout << "Array A sorted: " << (isSorted(A, 0) ? "true" : "false") << "\n";

    std::vector<int> B = {1, 5, 671, 1, 6, 3, 2, 0};
    std::cout << "Array B sorted: " << (isSorted(B, 0) ? "true" : "false") << "\n";
    return 0;
}
