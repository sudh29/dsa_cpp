#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> max_of_subarrays(int *arr, int n, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);

            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = sol.max_of_subarrays(arr, n, 3);
    cout << "Max of subarrays of size 3: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
