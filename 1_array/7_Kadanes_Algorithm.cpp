#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(int arr[], int n) {
        long long max_so_far = LLONG_MIN, current_max = 0;
        for (int i = 0; i < n; i++) {
            current_max += arr[i];
            if (max_so_far < current_max) max_so_far = current_max;
            if (current_max < 0) current_max = 0;
        }
        return max_so_far;
    }
};

int main() {
    Solution sol;
    int arr[] = {1, 2, 3, -2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max contiguous subarray sum: " << sol.maxSubarraySum(arr, n) << endl;
    return 0;
}
