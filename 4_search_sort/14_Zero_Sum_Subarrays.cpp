#include <cassert>
#include <iostream>
#include <span>
#include <unordered_map>
#include <vector>

class Solution {
public:
    long long findSubarray(std::span<const long long> arr) {
        std::unordered_map<long long, long long> mp;
        long long sum = 0, count = 0;
        mp[0] = 1;
        for (long long v : arr) {
            sum += v;
            if (auto it = mp.find(sum); it != mp.end()) {
                count += it->second;
            }
            mp[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<long long> arr1 = {0, 0, 5, 5, 0, 0};
    assert(sol.findSubarray(arr1) == 6);

    std::vector<long long> arr2 = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    assert(sol.findSubarray(arr2) == 4);

    assert(sol.findSubarray({}) == 0);

    std::cout << "14_Zero_Sum_Subarrays tests passed.\n";
    return 0;
}
