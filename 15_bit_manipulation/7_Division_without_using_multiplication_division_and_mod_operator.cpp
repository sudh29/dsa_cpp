#include <iostream>
#include <climits>
#include <cstdlib>
#include <cassert>

using namespace std;

class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        if (divisor == 0) return LLONG_MAX;
        if (dividend == 0) return 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        unsigned long long dvd = llabs(dividend);
        unsigned long long dvs = llabs(divisor);
        unsigned long long quotient = 0;

        for (int i = 62; i >= 0; i--) {
            if ((dvd >> i) >= dvs) {
                dvd -= (dvs << i);
                quotient += (1ULL << i);
            }
        }
        return sign * (long long)quotient;
    }
};

int main() {
    Solution sol;
    cout << "10 / 3 = " << sol.divide(10, 3) << endl;
    cout << "43 / -8 = " << sol.divide(43, -8) << endl;
    cout << "1000000000000 / 2 = " << sol.divide(1000000000000LL, 2LL) << endl;
    assert(sol.divide(10, 3) == 3);
    assert(sol.divide(43, -8) == -5);
    assert(sol.divide(1000000000000LL, 2LL) == 500000000000LL);
    return 0;
}
