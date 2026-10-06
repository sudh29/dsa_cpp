#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Node {
        int val, row, col;
        bool operator>(const Node &other) const { return val > other.val; }
    };

    pair<int, int> findSmallestRange(vector<vector<int>> &KSortedArray, int n, int k) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int max_val = INT_MIN;

        for (int i = 0; i < k; i++) {
            pq.push({KSortedArray[i][0], i, 0});
            max_val = max(max_val, KSortedArray[i][0]);
        }

        int start = -1, end = -1, min_range = INT_MAX;

        while (true) {
            auto top = pq.top();
            pq.pop();
            int min_val = top.val;

            if (max_val - min_val < min_range) {
                min_range = max_val - min_val;
                start = min_val;
                end = max_val;
            }

            if (top.col + 1 < n) {
                int next_val = KSortedArray[top.row][top.col + 1];
                pq.push({next_val, top.row, top.col + 1});
                max_val = max(max_val, next_val);
            } else {
                break;
            }
        }
        return {start, end};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {1, 3, 5, 7, 9},
        {0, 2, 4, 6, 8},
        {2, 3, 5, 7, 11}
    };
    auto range = sol.findSmallestRange(arr, 5, 3);
    cout << "Smallest range covering all K lists: [" << range.first << ", " << range.second << "]" << endl;
    return 0;
}
