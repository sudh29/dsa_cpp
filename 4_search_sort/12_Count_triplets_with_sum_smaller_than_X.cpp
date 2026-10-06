#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    long long countTriplets(std::vector<long long> arr, long long sum) {
        std::sort(arr.begin(), arr.end());
        int n = static_cast<int>(arr.size());
        long long count = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] < sum) {
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<long long> arr1 = {-2, 0, 1, 3};
    assert(sol.countTriplets(arr1, 2) == 2);

    std::vector<long long> arr2 = {5, 1, 3, 4, 7};
    assert(sol.countTriplets(arr2, 12) == 4);

    std::cout << "12_Count_triplets_with_sum_smaller_than_X tests passed.\n";
    return 0;
}
