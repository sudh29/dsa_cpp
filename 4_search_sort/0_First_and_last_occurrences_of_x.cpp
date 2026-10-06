#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

std::vector<int> find(std::span<const int> arr, int x) {
    int n = static_cast<int>(arr.size());
    int start = 0, end = n - 1, temp = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            temp = mid;
            break;
        } else if (arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (temp == -1) return {-1, -1};

    int first = temp, last = temp;
    while (first > 0 && arr[first - 1] == x) first--;
    while (last < n - 1 && arr[last + 1] == x) last++;

    return {first, last};
}

int main() {
    std::vector<int> arr = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    assert(find(arr, 5) == (std::vector<int>{2, 5}));
    assert(find(arr, 1) == (std::vector<int>{0, 0}));
    assert(find(arr, 125) == (std::vector<int>{8, 8}));
    assert(find(arr, 999) == (std::vector<int>{-1, -1}));
    assert(find({}, 5) == (std::vector<int>{-1, -1}));

    std::cout << "0_First_and_last_occurrences_of_x tests passed.\n";
    return 0;
}
