#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / n, c = mid % n;
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    cout << "Search " << target << ": " << (sol.searchMatrix(mat, target) ? "Found" : "Not Found") << endl;
    return 0;
}
