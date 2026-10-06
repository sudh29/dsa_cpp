#include <iostream>
#include <vector>

bool isSafe(int r, int c, const std::vector<std::vector<int>>& board, int n) {
    // Check left row
    for (int i = 0; i < c; ++i) {
        if (board[r][i]) return false;
    }
    // Check upper left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }
    // Check lower left diagonal
    for (int i = r, j = c; i < n && j >= 0; ++i, --j) {
        if (board[i][j]) return false;
    }
    return true;
}

void solve(int col, std::vector<int>& buf, std::vector<std::vector<int>>& result,
           std::vector<std::vector<int>>& board, int n) {
    if (col >= n) {
        result.push_back(buf);
        return;
    }
    for (int r = 0; r < n; ++r) {
        if (isSafe(r, col, board, n)) {
            board[r][col] = 1;
            buf.push_back(r + 1);
            solve(col + 1, buf, result, board, n);
            buf.pop_back();
            board[r][col] = 0;
        }
    }
}

std::vector<std::vector<int>> nQueen(int n) {
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> result;
    std::vector<int> buf;
    solve(0, buf, result, board, n);
    return result;
}

int main() {
    int n = 4;
    auto solutions = nQueen(n);
    std::cout << "N-Queens (n=4) solutions count: " << solutions.size() << "\n";
    for (const auto& sol : solutions) {
        std::cout << "[ ";
        for (int row : sol) std::cout << row << " ";
        std::cout << "]\n";
    }
    return 0;
}
