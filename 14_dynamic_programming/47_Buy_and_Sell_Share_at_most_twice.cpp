#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(int n, const std::vector<int>& price) {
    if (n <= 1) return 0;

    std::vector<int> left_profit(n, 0);
    std::vector<int> right_profit(n, 0);

    int min_price = price[0];
    for (int i = 1; i < n; ++i) {
        min_price = std::min(min_price, price[i]);
        left_profit[i] = std::max(left_profit[i - 1], price[i] - min_price);
    }

    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_price = std::max(max_price, price[i]);
        right_profit[i] = std::max(right_profit[i + 1], max_price - price[i]);
    }

    int total_max = 0;
    for (int i = 0; i < n; ++i) {
        total_max = std::max(total_max, left_profit[i] + right_profit[i]);
    }
    return total_max;
}

int main() {
    std::vector<int> prices = {10, 22, 5, 75, 65, 80};
    std::cout << "Max profit at most twice: " << maxProfit(prices.size(), prices) << " (expected 87)\n";
    return 0;
}
