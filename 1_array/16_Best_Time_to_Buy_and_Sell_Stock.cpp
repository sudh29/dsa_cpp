#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    int maxProfit(std::span<const int> prices) {
        if (prices.empty()) return 0;
        int minPrice = prices[0];
        int maxProf = 0;
        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProf = std::max(maxProf, price - minPrice);
        }
        return maxProf;
    }
};

int main() {
    Solution sol;
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(sol.maxProfit(prices1) == 5);

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    assert(sol.maxProfit(prices2) == 0);

    assert(sol.maxProfit(std::vector<int>{}) == 0);

    std::cout << "1_array 16_Best_Time_to_Buy_and_Sell_Stock: All tests passed.\n";
    return 0;
}
