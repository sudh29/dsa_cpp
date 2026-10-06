#include <iostream>
#include <vector>
#include <algorithm>

int maxSquare(int n, int m, const std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int max_side = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                max_side = std::max(max_side, dp[i][j]);
            }
        }
    }
    return max_side;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    std::cout << "Max square side with all 1s: " << maxSquare(mat.size(), mat[0].size(), mat) << " (expected 3)\n";
    return 0;
}
