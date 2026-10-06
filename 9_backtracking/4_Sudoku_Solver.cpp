#include <iostream>
#include <vector>

bool isValid(const std::vector<std::vector<int>>& grid, int row, int col, int guess) {
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == guess || grid[i][col] == guess) return false;
    }
    int start_r = (row / 3) * 3;
    int start_c = (col / 3) * 3;
    for (int r = start_r; r < start_r + 3; ++r) {
        for (int c = start_c; c < start_c + 3; ++c) {
            if (grid[r][c] == guess) return false;
        }
    }
    return true;
}

bool solveSudoku(std::vector<std::vector<int>>& grid) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) {
                for (int guess = 1; guess <= 9; ++guess) {
                    if (isValid(grid, r, c, guess)) {
                        grid[r][c] = guess;
                        if (solveSudoku(grid)) return true;
                        grid[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid)) {
        std::cout << "Sudoku solved successfully:\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "No solution exists\n";
    }
    return 0;
}
