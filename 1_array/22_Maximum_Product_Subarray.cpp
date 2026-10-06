#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxProduct(vector<int> arr, int n) {
        long long max_prod = arr[0];
        long long cur_max = arr[0], cur_min = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < 0) swap(cur_max, cur_min);
            cur_max = max((long long)arr[i], cur_max * arr[i]);
            cur_min = min((long long)arr[i], cur_min * arr[i]);
            max_prod = max(max_prod, cur_max);
        }
        return max_prod;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {6, -3, -10, 0, 2};
    cout << "Max product subarray: " << sol.maxProduct(arr, arr.size()) << endl;
    return 0;
}
