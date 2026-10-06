#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

int main() {
    std::cout << "=== C++ STL Containers (Vector, Map, Set) ===" << std::endl;

    // std::vector
    std::vector<int> nums = {5, 2, 9, 1, 5, 6};
    std::sort(nums.begin(), nums.end());
    std::cout << "Sorted vector: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // std::unordered_set
    std::unordered_set<int> unique_vals(nums.begin(), nums.end());
    std::cout << "Unique elements count: " << unique_vals.size() << std::endl;

    // std::unordered_map
    std::unordered_map<std::string, int> freq;
    freq["apple"] = 3;
    freq["banana"] = 5;
    for (const auto &[key, count] : freq) {
        std::cout << "Key: " << key << " -> Value: " << count << std::endl;
    }

    return 0;
}
