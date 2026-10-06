#include <iostream>

using namespace std;

class Solution {
public:
    int findLargestPowerOf2(int n) {
        int x = 0;
        while ((1 << x) <= n) x++;
        return x - 1;
    }

    int countSetBits(int n) {
        if (n <= 0) return 0;
        int x = findLargestPowerOf2(n);
        int bits_up_to_2_pow_x = x * (1 << (x - 1));
        int msb_from_2_pow_x_to_n = n - (1 << x) + 1;
        int rest = n - (1 << x);
        return bits_up_to_2_pow_x + msb_from_2_pow_x_to_n + countSetBits(rest);
    }
};

int main() {
    Solution sol;
    int n = 4;
    cout << "Total set bits from 1 to " << n << ": " << sol.countSetBits(n) << endl;
    return 0;
}
