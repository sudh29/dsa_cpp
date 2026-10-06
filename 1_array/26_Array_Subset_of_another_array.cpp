#include <cassert>
#include <iostream>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

std::string isSubset(std::span<const int> a1, std::span<const int> a2) {
    std::unordered_map<int, int> freq;
    for (int v : a1) freq[v]++;
    for (int v : a2) {
        if (freq[v] <= 0) return "No";
        freq[v]--;
    }
    return "Yes";
}

int main() {
    std::vector<int> a1 = {11, 1, 13, 21, 3, 7};
    std::vector<int> a2 = {11, 3, 7, 1};
    assert(isSubset(a1, a2) == "Yes");

    std::vector<int> a3 = {1, 2, 3};
    std::vector<int> a4 = {1, 2, 3, 4};
    assert(isSubset(a3, a4) == "No");

    std::vector<int> empty;
    assert(isSubset(a1, empty) == "Yes");

    std::cout << "1_array 26_Array_Subset_of_another_array: All tests passed.\n";
    return 0;
}
