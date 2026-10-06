#include <iostream>

using namespace std;

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
    int n = 6;
    cout << "Smallest number whose factorial has at least " << n << " trailing zeros: " << sol.findNum(n) << endl;
    return 0;
}
