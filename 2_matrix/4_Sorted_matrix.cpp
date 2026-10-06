#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        int k = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Mat[i][j] = temp[k++];
            }
        }
        return Mat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    auto sorted = sol.sortedMatrix(4, mat);
    cout << "Sorted Matrix [0][0]: " << sorted[0][0] << ", [3][3]: " << sorted[3][3] << endl;
    return 0;
}
