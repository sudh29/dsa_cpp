#include <iostream>
#include <vector>
#include <algorithm>

int maximizeTheCuts(int n, int x, int y, int z) {
    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        if (i >= x && dp[i - x] != -1) dp[i] = std::max(dp[i], dp[i - x] + 1);
        if (i >= y && dp[i - y] != -1) dp[i] = std::max(dp[i], dp[i - y] + 1);
        if (i >= z && dp[i - z] != -1) dp[i] = std::max(dp[i], dp[i - z] + 1);
    }
    return std::max(dp[n], 0);
}

int main() {
    std::cout << "Max cuts for n=4, cuts=(2,1,1): " << maximizeTheCuts(4, 2, 1, 1) << " (expected 4)\n";
    std::cout << "Max cuts for n=5, cuts=(5,3,2): " << maximizeTheCuts(5, 5, 3, 2) << " (expected 2)\n";
    return 0;
}
