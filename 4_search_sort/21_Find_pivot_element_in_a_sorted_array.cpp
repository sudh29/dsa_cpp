#include <cassert>
#include <iostream>
#include <span>
#include <vector>

int getPivotElement(std::span<const int> arr, int left, int right) {
    if (right < left) return -1;
    if (right == left) return left;

    int mid = left + (right - left) / 2;
    if (mid < right && arr[mid] > arr[mid + 1])
        return mid + 1;
    if (mid > left && arr[mid] < arr[mid - 1])
        return mid;

    if (arr[right] > arr[mid])
        return getPivotElement(arr, left, mid - 1);
    return getPivotElement(arr, mid + 1, right);
}

int main() {
    std::vector<int> arr1 = {4, 5, 6, 7, 8, 1, 2, 3};
    int p1 = getPivotElement(arr1, 0, static_cast<int>(arr1.size()) - 1);
    assert(p1 == 5 && arr1[p1] == 1);

    std::vector<int> arr2 = {1, 2, 3};
    int p2 = getPivotElement(arr2, 0, static_cast<int>(arr2.size()) - 1);
    assert(p2 == 0);

    std::vector<int> arr3 = {2, 1};
    int p3 = getPivotElement(arr3, 0, static_cast<int>(arr3.size()) - 1);
    assert(p3 == 1 && arr3[p3] == 1);

    std::cout << "21_Find_pivot_element_in_a_sorted_array tests passed.\n";
    return 0;
}
