#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        vector<int> v(arr + l, arr + r + 1);
        nth_element(v.begin(), v.begin() + k - 1, v.end());
        return v[k - 1];
    }
};

int main() {
    Solution sol;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << k << "-th smallest: " << sol.kthSmallest(arr, 0, n - 1, k) << endl;
    return 0;
}
