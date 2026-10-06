#include <iostream>
#include <vector>

long long findCatalan(int N) {
    const long long MOD = 1000000007;
    std::vector<long long> dp(N + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % MOD) % MOD;
        }
    }
    return dp[N];
}

int main() {
    std::cout << "Catalan(5): " << findCatalan(5) << " (expected 42)\n";
    std::cout << "Catalan(4): " << findCatalan(4) << " (expected 14)\n";
    return 0;
}
