#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr, int n, int m) {
        int max_row_idx = -1;
        int j = m - 1;

        for (int i = 0; i < n; i++) {
            while (j >= 0 && arr[i][j] == 1) {
                j--;
                max_row_idx = i;
            }
        }
        return max_row_idx;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    cout << "Row with max 1s: " << sol.rowWithMax1s(arr, 4, 4) << endl;
    return 0;
}
