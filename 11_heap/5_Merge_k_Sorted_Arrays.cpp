#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct Element {
        int val, row, col;
        bool operator>(const Element &other) const { return val > other.val; }
    };

    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<Element, vector<Element>, greater<Element>> pq;
        for (int i = 0; i < K; i++) pq.push({arr[i][0], i, 0});

        vector<int> res;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.val);
            if (top.col + 1 < (int)arr[top.row].size()) {
                pq.push({arr[top.row][top.col + 1], top.row, top.col + 1});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto merged = sol.mergeKArrays(arr, 3);
    cout << "Merged K sorted arrays: ";
    for (int v : merged) cout << v << " ";
    cout << endl;
    return 0;
}
