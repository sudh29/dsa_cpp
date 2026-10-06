#include <cassert>
#include <cmath>
#include <iostream>

class Solution {
public:
    int countSquares(int N) {
        if (N <= 1) return 0;
        int sq = static_cast<int>(std::sqrt(N - 1));
        return sq;
    }
};

int main() {
    Solution sol;
    assert(sol.countSquares(9) == 2);
    assert(sol.countSquares(1) == 0);
    assert(sol.countSquares(0) == 0);
    assert(sol.countSquares(16) == 3);
    assert(sol.countSquares(25) == 4);
    assert(sol.countSquares(26) == 5);

    std::cout << "3_Count_Squares tests passed.\n";
    return 0;
}
