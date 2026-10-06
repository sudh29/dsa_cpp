#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Find max value of mat[c][d] - mat[a][b] such that c > a and d > b
int findMaxValue(const vector<vector<int>> &mat) {
    int n = mat.size();
    vector<vector<int>> maxArr(n, vector<int>(n));

    maxArr[n - 1][n - 1] = mat[n - 1][n - 1];
    for (int j = n - 2; j >= 0; j--)
        maxArr[n - 1][j] = max(mat[n - 1][j], maxArr[n - 1][j + 1]);
    for (int i = n - 2; i >= 0; i--)
        maxArr[i][n - 1] = max(mat[i][n - 1], maxArr[i + 1][n - 1]);

    int max_val = INT_MIN;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            max_val = max(max_val, maxArr[i + 1][j + 1] - mat[i][j]);
            maxArr[i][j] = max(mat[i][j], max({maxArr[i + 1][j], maxArr[i][j + 1], maxArr[i + 1][j + 1]}));
        }
    }
    return max_val;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, -10, -4},
        {-8, -3, 4, 2},
        {3, 8, 6, 1},
        {-1, -1, 1, 1}
    };
    cout << "Specific pair max value: " << findMaxValue(mat) << endl;
    return 0;
}
