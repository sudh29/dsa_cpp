#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> factorial(int N) {
        if (N < 0) return {};
        std::vector<int> res;
        res.push_back(1);

        for (int x = 2; x <= N; ++x) {
            int carry = 0;
            for (size_t i = 0; i < res.size(); ++i) {
                int prod = res[i] * x + carry;
                res[i] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                res.push_back(carry % 10);
                carry /= 10;
            }
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    auto f5 = sol.factorial(5);
    std::vector<int> exp5 = {1, 2, 0};
    assert(f5 == exp5);

    auto f10 = sol.factorial(10);
    // 10! = 3628800
    std::vector<int> exp10 = {3, 6, 2, 8, 8, 0, 0};
    assert(f10 == exp10);

    auto f1 = sol.factorial(1);
    assert(f1 == (std::vector<int>{1}));

    std::cout << "1_array 21_Factorials_of_large_numbers: All tests passed.\n";
    return 0;
}
