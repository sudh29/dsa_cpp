#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {
        sort(candies, candies + N);
        int min_amt = 0, max_amt = 0;

        int i = 0, j = N - 1;
        while (i <= j) {
            min_amt += candies[i++];
            j -= K;
        }

        i = N - 1; j = 0;
        while (i >= j) {
            max_amt += candies[i--];
            j += K;
        }
        return {min_amt, max_amt};
    }
};

int main() {
    Solution sol;
    int candies[] = {3, 2, 1, 4};
    auto res = sol.candyStore(candies, 4, 2);
    cout << "Min candy amount: " << res[0] << ", Max candy amount: " << res[1] << endl;
    return 0;
}
