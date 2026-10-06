#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // At most two transactions
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;

        for (int p : prices) {
            buy1 = min(buy1, p);
            profit1 = max(profit1, p - buy1);
            buy2 = min(buy2, p - profit1);
            profit2 = max(profit2, p - buy2);
        }
        return profit2;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << "Max profit with 2 transactions: " << sol.maxProfit(prices) << endl;
    return 0;
}
