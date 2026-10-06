#include <iostream>
#include <vector>

long long getCount(int n) {
    if (n == 1) return 10;

    std::vector<std::vector<int>> moves = {
        {0, 8},
        {1, 2, 4},
        {2, 1, 3, 5},
        {3, 2, 6},
        {4, 1, 5, 7},
        {5, 2, 4, 6, 8},
        {6, 3, 5, 9},
        {7, 4, 8},
        {8, 5, 7, 9, 0},
        {9, 6, 8}
    };

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(10, 0));
    for (int j = 0; j < 10; ++j) dp[1][j] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k : moves[j]) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    long long total = 0;
    for (int j = 0; j < 10; ++j) total += dp[n][j];
    return total;
}

int main() {
    std::cout << "Keypad count n=1: " << getCount(1) << " (expected 10)\n";
    std::cout << "Keypad count n=2: " << getCount(2) << " (expected 36)\n";
    return 0;
}
