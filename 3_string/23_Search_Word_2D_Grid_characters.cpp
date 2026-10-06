#include <array>
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    static constexpr std::array<int, 8> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static constexpr std::array<int, 8> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool search2D(const std::vector<std::vector<char>>& grid, int row, int col, std::string_view word) {
        if (grid[row][col] != word[0]) return false;
        int R = static_cast<int>(grid.size());
        int C = static_cast<int>(grid[0].size());
        int len = static_cast<int>(word.length());

        for (int dir = 0; dir < 8; dir++) {
            int k = 1;
            int rd = row + dx[dir];
            int cd = col + dy[dir];
            for (; k < len; k++) {
                if (rd < 0 || rd >= R || cd < 0 || cd >= C || grid[rd][cd] != word[k])
                    break;
                rd += dx[dir];
                cd += dy[dir];
            }
            if (k == len) return true;
        }
        return false;
    }

    std::vector<std::vector<int>> searchWord(const std::vector<std::vector<char>>& grid, std::string_view word) {
        std::vector<std::vector<int>> res;
        if (grid.empty() || grid[0].empty() || word.empty()) return res;
        int R = static_cast<int>(grid.size());
        int C = static_cast<int>(grid[0].size());
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (search2D(grid, i, j, word)) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> grid = {
        {'a', 'b', 'c'},
        {'d', 'r', 'f'},
        {'g', 'h', 'i'}
    };
    auto matches = sol.searchWord(grid, "abc");
    assert(matches.size() == 1 && matches[0][0] == 0 && matches[0][1] == 0);

    auto matches2 = sol.searchWord(grid, "cfi");
    assert(matches2.size() == 1 && matches2[0][0] == 0 && matches2[0][1] == 2);

    auto matches3 = sol.searchWord(grid, "xyz");
    assert(matches3.empty());

    std::cout << "23_Search_Word_2D_Grid_characters tests passed.\n";
    return 0;
}
