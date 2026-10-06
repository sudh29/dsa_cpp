#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {price[i], i + 1};
        sort(v.begin(), v.end());

        int count = 0;
        for (int i = 0; i < n; i++) {
            int maxCanBuy = min(v[i].second, k / v[i].first);
            count += maxCanBuy;
            k -= maxCanBuy * v[i].first;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int price[] = {10, 7, 19};
    cout << "Max stocks bought with $45: " << sol.buyMaximumProducts(3, 45, price) << endl;
    return 0;
}
