#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> candyStore(std::vector<int> candies, int K) {
        int N = static_cast<int>(candies.size());
        if (N == 0) return {0, 0};
        std::sort(candies.begin(), candies.end());
        int min_amt = 0, max_amt = 0;

        int i = 0, j = N - 1;
        while (i <= j) {
            min_amt += candies[i++];
            j -= K;
        }

        i = N - 1;
        j = 0;
        while (i >= j) {
            max_amt += candies[i--];
            j += K;
        }
        return {min_amt, max_amt};
    }
};

int main() {
    Solution sol;
    std::vector<int> candies1 = {3, 2, 1, 4};
    auto res1 = sol.candyStore(candies1, 2);
    assert(res1[0] == 3 && res1[1] == 7);

    std::vector<int> candies2 = {5};
    auto res2 = sol.candyStore(candies2, 1);
    assert(res2[0] == 5 && res2[1] == 5);

    auto res3 = sol.candyStore({}, 1);
    assert(res3[0] == 0 && res3[1] == 0);

    std::cout << "9_Find_minimum_maximum_amount_to_buy_all_N_candies tests passed.\n";
    return 0;
}
