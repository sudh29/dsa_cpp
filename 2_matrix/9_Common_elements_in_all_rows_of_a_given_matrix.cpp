#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> distinct(vector<vector<int>> &M, int N) {
        unordered_map<int, int> mp;
        for (int j = 0; j < N; j++) {
            mp[M[0][j]] = 1;
        }

        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mp[M[i][j]] == i) {
                    mp[M[i][j]] = i + 1;
                }
            }
        }

        vector<int> res;
        for (const auto &[val, count] : mp) {
            if (count == N) {
                res.push_back(val);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {2, 1, 4, 3},
        {1, 2, 3, 2},
        {3, 6, 2, 3},
        {5, 2, 5, 3}
    };
    auto common = sol.distinct(mat, 4);
    cout << "Common elements across all rows: ";
    for (int v : common) cout << v << " ";
    cout << endl;
    return 0;
}
