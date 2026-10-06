#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    long long int findMaxProduct(const std::vector<int>& a) {
        int n = static_cast<int>(a.size());
        if (n == 0) return 0;
        if (n == 1) return a[0];
        constexpr long long int MOD = 1e9 + 7;
        int zeroCount = 0, negCount = 0;
        int maxNeg = INT_MIN;
        long long int prod = 1;

        for (int v : a) {
            if (v == 0) {
                zeroCount++;
                continue;
            }
            if (v < 0) {
                negCount++;
                maxNeg = std::max(maxNeg, v);
            }
            prod = (prod * v) % MOD;
        }

        if (zeroCount == n) return 0;
        if (negCount % 2 != 0) {
            if (negCount == 1 && zeroCount + negCount == n) return 0;
            prod /= maxNeg;
        }
        return (prod % MOD + MOD) % MOD;
    }
};

int main() {
    Solution sol;
    std::vector<int> a1 = {-1, -1, -2, 4, 3};
    assert(sol.findMaxProduct(a1) == 24);

    std::vector<int> a2 = {0, 0, 0};
    assert(sol.findMaxProduct(a2) == 0);

    std::vector<int> a3 = {-1};
    assert(sol.findMaxProduct(a3) == -1);

    std::vector<int> a4 = {2, 3, 4};
    assert(sol.findMaxProduct(a4) == 24);

    std::cout << "14_Maximum_product_subset_array tests passed.\n";
    return 0;
}
