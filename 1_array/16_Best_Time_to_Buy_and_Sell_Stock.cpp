#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9, max_profit = 0;
        for (int price : prices) {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max stock profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
