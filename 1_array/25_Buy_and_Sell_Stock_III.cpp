#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    // At most two transactions
    int maxProfit(std::span<const int> prices) {
        if (prices.empty()) return 0;
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for (int p : prices) {
            buy1 = std::min(buy1, p);
            profit1 = std::max(profit1, p - buy1);
            buy2 = std::min(buy2, p - profit1);
            profit2 = std::max(profit2, p - buy2);
        }
        return profit2;
    }
};

int main() {
    Solution sol;
    std::vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    // Buy at 0, sell at 3 (profit 3). Buy at 1, sell at 4 (profit 3). Total = 6.
    assert(sol.maxProfit(prices1) == 6);

    std::vector<int> prices2 = {1, 2, 3, 4, 5};
    assert(sol.maxProfit(prices2) == 4);

    std::vector<int> prices3 = {7, 6, 4, 3, 1};
    assert(sol.maxProfit(prices3) == 0);

    std::cout << "1_array 25_Buy_and_Sell_Stock_III: All tests passed.\n";
    return 0;
}
