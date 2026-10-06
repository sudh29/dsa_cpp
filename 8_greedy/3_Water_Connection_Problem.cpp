#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(int w, int &minDia, int &endpoint, const vector<int> &cd, const vector<int> &wt) {
        if (cd[w] == 0) {
            endpoint = w;
            return;
        }
        minDia = min(minDia, wt[w]);
        dfs(cd[w], minDia, endpoint, cd, wt);
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
        vector<int> cd(n + 1, 0), rd(n + 1, 0), wt(n + 1, 0);

        for (int i = 0; i < p; i++) {
            cd[a[i]] = b[i];
            wt[a[i]] = d[i];
            rd[b[i]] = a[i];
        }

        vector<vector<int>> res;
        for (int j = 1; j <= n; j++) {
            if (rd[j] == 0 && cd[j] > 0) {
                int minDia = 1e9, endpoint = 0;
                dfs(j, minDia, endpoint, cd, wt);
                res.push_back({j, endpoint, minDia});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = {7, 5, 4, 2, 9, 3};
    vector<int> b = {4, 9, 6, 8, 7, 1};
    vector<int> d = {98, 72, 10, 22, 17, 66};
    auto res = sol.solve(9, 6, a, b, d);
    cout << "Water connection components count: " << res.size() << endl;
    return 0;
}
