#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> nums) {
        int xor_all = 0;
        for (int v : nums) xor_all ^= v;

        // Find rightmost set bit
        int rightmost = xor_all & (-xor_all);
        int a = 0, b = 0;

        for (int v : nums) {
            if (v & rightmost) a ^= v;
            else b ^= v;
        }

        if (a > b) swap(a, b);
        return {a, b};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2, 1, 4};
    auto res = sol.singleNumber(nums);
    cout << "Two non-repeating numbers: " << res[0] << " and " << res[1] << endl;
    return 0;
}
