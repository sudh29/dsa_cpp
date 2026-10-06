#include <iostream>
#include <string>
#include <vector>

bool isInterleave(const std::string& A, const std::string& B, const std::string& C) {
    int n = A.length();
    int m = B.length();
    int l = C.length();
    if (n + m != l) return false;

    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = dp[0][j - 1] && (B[j - 1] == C[j - 1]);
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i + j - 1]) ||
                       (dp[i][j - 1] && B[j - 1] == C[i + j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    std::string A = "aabcc", B = "dbbca", C = "aadbbcbcac";
    std::cout << "Is interleaved: " << (isInterleave(A, B, C) ? "YES" : "NO") << " (expected YES)\n";
    std::cout << "Is interleaved: " << (isInterleave("aabcc", "dbbca", "aadbbbaccc") ? "YES" : "NO") << " (expected NO)\n";
    return 0;
}
