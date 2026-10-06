#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int LCSof3(const std::string& A, const std::string& B, const std::string& C, int n1, int n2, int n3) {
    std::vector<std::vector<std::vector<int>>> dp(
        n1 + 1, std::vector<std::vector<int>>(n2 + 1, std::vector<int>(n3 + 1, 0)));

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            for (int k = 1; k <= n3; ++k) {
                if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = std::max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int main() {
    std::string s1 = "geeks";
    std::string s2 = "geeksfor";
    std::string s3 = "geeksforgeeks";
    std::cout << "LCS of 3 strings: " << LCSof3(s1, s2, s3, s1.length(), s2.length(), s3.length()) << " (expected 5)\n";
    return 0;
}
