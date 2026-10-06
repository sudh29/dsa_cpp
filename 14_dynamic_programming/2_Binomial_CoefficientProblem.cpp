#include <iostream>
#include <vector>
#include <algorithm>

int nCr(int n, int r) {
    if (r > n) return 0;
    const int MOD = 1000000007;
    std::vector<int> dp(r + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, r); j > 0; --j) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    return dp[r];
}

int main() {
    std::cout << "C(5, 2): " << nCr(5, 2) << " (expected 10)\n";
    std::cout << "C(3, 2): " << nCr(3, 2) << " (expected 3)\n";
    return 0;
}
