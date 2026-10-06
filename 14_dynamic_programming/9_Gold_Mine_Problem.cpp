#include <iostream>
#include <vector>
#include <algorithm>

int maxGold(int n, int m, std::vector<std::vector<int>> M) {
    for (int col = m - 2; col >= 0; --col) {
        for (int row = 0; row < n; ++row) {
            int right = M[row][col + 1];
            int right_up = (row > 0) ? M[row - 1][col + 1] : 0;
            int right_down = (row < n - 1) ? M[row + 1][col + 1] : 0;
            M[row][col] += std::max({right, right_up, right_down});
        }
    }
    int max_gold = 0;
    for (int row = 0; row < n; ++row) {
        max_gold = std::max(max_gold, M[row][0]);
    }
    return max_gold;
}

int main() {
    std::vector<std::vector<int>> mine = {
        {1, 3, 3},
        {2, 1, 4},
        {0, 6, 4}
    };
    std::cout << "Max gold: " << maxGold(3, 3, mine) << " (expected 12)\n";
    return 0;
}
