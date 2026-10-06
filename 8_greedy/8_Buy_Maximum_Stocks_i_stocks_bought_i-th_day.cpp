#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

class Solution {
public:
    int buyMaximumProducts(int k, std::span<const int> price) {
        int n = static_cast<int>(price.size());
        std::vector<std::pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {price[i], i + 1};
        std::sort(v.begin(), v.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            int maxCanBuy = std::min(v[i].second, k / v[i].first);
            count += maxCanBuy;
            k -= maxCanBuy * v[i].first;
        }
        return count;
    }
};

int main() {
    Solution sol;
    std::vector<int> price1 = {10, 7, 19};
    assert(sol.buyMaximumProducts(45, price1) == 4);

    std::vector<int> price2 = {7, 10, 4};
    assert(sol.buyMaximumProducts(100, price2) == 6);

    assert(sol.buyMaximumProducts(10, {}) == 0);

    std::cout << "8_Buy_Maximum_Stocks_i_stocks_bought_i-th_day tests passed.\n";
    return 0;
}
