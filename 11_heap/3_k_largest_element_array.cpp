#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < n; i++) {
            minH.push(arr[i]);
            if (minH.size() > (size_t)k) minH.pop();
        }
        vector<int> res;
        while (!minH.empty()) {
            res.push_back(minH.top());
            minH.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    int arr[] = {12, 5, 787, 1, 23};
    auto res = sol.kLargest(arr, 5, 2);
    cout << "2 largest elements: " << res[0] << " " << res[1] << endl;
    return 0;
}
