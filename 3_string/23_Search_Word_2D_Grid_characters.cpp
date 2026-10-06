#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    bool search2D(vector<vector<char>> &grid, int row, int col, string word) {
        if (grid[row][col] != word[0]) return false;
        int R = grid.size(), C = grid[0].size(), len = word.length();

        for (int dir = 0; dir < 8; dir++) {
            int k, rd = row + dx[dir], cd = col + dy[dir];
            for (k = 1; k < len; k++) {
                if (rd < 0 || rd >= R || cd < 0 || cd >= C || grid[rd][cd] != word[k])
                    break;
                rd += dx[dir];
                cd += dy[dir];
            }
            if (k == len) return true;
        }
        return false;
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        vector<vector<int>> res;
        int R = grid.size(), C = grid[0].size();
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
    vector<vector<char>> grid = {
        {'a', 'b', 'c'},
        {'d', 'r', 'f'},
        {'g', 'h', 'i'}
    };
    auto matches = sol.searchWord(grid, "abc");
    cout << "Word found starting at: [" << matches[0][0] << ", " << matches[0][1] << "]\n";
    return 0;
}
