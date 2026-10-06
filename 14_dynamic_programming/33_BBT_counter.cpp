#include <iostream>
#include <vector>

long long countBT(int h) {
    const long long MOD = 1000000007;
    if (h == 0 || h == 1) return 1;

    std::vector<long long> dp(h + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= h; ++i) {
        dp[i] = ((dp[i - 1] * dp[i - 1]) % MOD + (2LL * dp[i - 1] * dp[i - 2]) % MOD) % MOD;
    }
    return dp[h];
}

int main() {
    std::cout << "Balanced binary trees of height 2: " << countBT(2) << " (expected 3)\n";
    std::cout << "Balanced binary trees of height 3: " << countBT(3) << " (expected 15)\n";
    return 0;
}
