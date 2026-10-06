#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                    if (sum == k) {
                        res.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while (left < right && arr[left] == arr[left + 1]) left++;
                        while (left < right && arr[right] == arr[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < k) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int k = 0;
    auto quads = sol.fourSum(arr, k);
    cout << "Four sum quadruplets summing to " << k << ":\n";
    for (const auto &q : quads) {
        cout << "[" << q[0] << ", " << q[1] << ", " << q[2] << ", " << q[3] << "]\n";
    }
    return 0;
}
