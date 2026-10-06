#include <cassert>
#include <iostream>

class Solution {
public:
    int countTrailingZeros(int n) {
        int count = 0;
        for (int i = 5; n / i >= 1; i *= 5) {
            count += n / i;
        }
        return count;
    }

    int findNum(int n) {
        if (n == 1) return 5;
        int low = 0, high = 5 * n, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countTrailingZeros(mid) >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.findNum(1) == 5);
    assert(sol.findNum(6) == 25);
    assert(sol.findNum(2) == 10);
    assert(sol.findNum(3) == 15);

    std::cout << "28_Smallest_factorial_number tests passed.\n";
    return 0;
}
