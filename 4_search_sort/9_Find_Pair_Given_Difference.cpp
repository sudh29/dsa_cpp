#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool findPair(std::vector<int> arr, int n) {
    std::sort(arr.begin(), arr.end());
    int size = static_cast<int>(arr.size());
    int i = 0, j = 1;
    while (i < size && j < size) {
        if (i != j && arr[j] - arr[i] == n) {
            return true;
        } else if (arr[j] - arr[i] < n) {
            j++;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    std::vector<int> arr1 = {5, 20, 3, 2, 5, 80};
    assert(findPair(arr1, 78));

    std::vector<int> arr2 = {90, 70, 20, 80, 50};
    assert(!findPair(arr2, 45));

    std::vector<int> arr3 = {1, 2, 3};
    assert(!findPair(arr3, 0));

    std::vector<int> arr4 = {1, 2, 2, 3};
    assert(findPair(arr4, 0));

    std::cout << "9_Find_Pair_Given_Difference tests passed.\n";
    return 0;
}
