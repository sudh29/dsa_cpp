#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {nums[i], i};
        sort(v.begin(), v.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || v[i].second == i) continue;

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        return swaps;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 8, 5, 4};
    cout << "Min swaps to sort: " << sol.minSwaps(nums) << endl;
    return 0;
}
