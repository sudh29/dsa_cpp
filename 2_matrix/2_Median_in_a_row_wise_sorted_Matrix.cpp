#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSmallerThanMid(vector<int> &row, int mid) {
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }

    int median(vector<vector<int>> &matrix, int r, int c) {
        int low = 1, high = 1e9;
        int desired = (r * c + 1) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < r; i++) {
                count += countSmallerThanMid(matrix[i], mid);
            }
            if (count < desired) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " << sol.median(mat, 3, 3) << endl;
    return 0;
}
