#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>> &mat, int n, int k) {
    // Min-heap storing {val, {r, c}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < n; i++) {
        pq.push({mat[i][0], {i, 0}});
    }

    int res = -1;
    while (k-- > 0 && !pq.empty()) {
        auto top = pq.top();
        pq.pop();
        res = top.first;
        int r = top.second.first;
        int c = top.second.second;
        if (c + 1 < n) {
            pq.push({mat[r][c + 1], {r, c + 1}});
        }
    }
    return res;
}

int main() {
    vector<vector<int>> mat = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };
    int k = 3;
    cout << k << "-th smallest in matrix: " << kthSmallest(mat, 4, k) << endl;
    return 0;
}
