#include <iostream>
#include <vector>
#include <algorithm>

long long permutationCoeff(int n, int k) {
    if (k > n) return 0;
    const long long MOD = 1000000007;
    std::vector<long long> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = std::min(i, k); j > 0; --j) {
            dp[j] = (dp[j] + (1LL * j * dp[j - 1]) % MOD) % MOD;
        }
    }
    return dp[k];
}

int main() {
    std::cout << "P(10, 2): " << permutationCoeff(10, 2) << " (expected 90)\n";
    std::cout << "P(10, 3): " << permutationCoeff(10, 3) << " (expected 720)\n";
    return 0;
}
