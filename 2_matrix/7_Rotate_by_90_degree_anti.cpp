#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotateby90(vector<vector<int>>& matrix, int n) {
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each column for 90 degree anti-clockwise
        for (int j = 0; j < n; j++) {
            int top = 0, bottom = n - 1;
            while (top < bottom) {
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    sol.rotateby90(mat, 3);
    cout << "Rotated 90 deg anti-clockwise [0][0]: " << mat[0][0] << ", [0][2]: " << mat[0][2] << endl;
    return 0;
}
