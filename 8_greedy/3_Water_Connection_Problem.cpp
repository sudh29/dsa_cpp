#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    void dfs(int w, int& minDia, int& endpoint, const std::vector<int>& cd, const std::vector<int>& wt) {
        if (cd[w] == 0) {
            endpoint = w;
            return;
        }
        minDia = std::min(minDia, wt[w]);
        dfs(cd[w], minDia, endpoint, cd, wt);
    }

    std::vector<std::vector<int>> solve(int n, int p, std::span<const int> a, std::span<const int> b, std::span<const int> d) {
        std::vector<int> cd(n + 1, 0), rd(n + 1, 0), wt(n + 1, 0);

        for (int i = 0; i < p; i++) {
            cd[a[i]] = b[i];
            wt[a[i]] = d[i];
            rd[b[i]] = a[i];
        }

        std::vector<std::vector<int>> res;
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
    std::vector<int> a = {7, 5, 4, 2, 9, 3};
    std::vector<int> b = {4, 9, 6, 8, 7, 1};
    std::vector<int> d = {98, 72, 10, 22, 17, 66};
    auto res = sol.solve(9, 6, a, b, d);
    assert(res.size() == 3);

    std::cout << "3_Water_Connection_Problem tests passed.\n";
    return 0;
}
