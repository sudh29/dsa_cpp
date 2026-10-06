#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> res(n, 1);
        long long left = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left;
            left *= nums[i];
        }
        long long right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<long long int> nums = {10, 3, 5, 6, 2};
    auto res = sol.productExceptSelf(nums, nums.size());
    cout << "Product except self: ";
    for (auto v : res) cout << v << " ";
    cout << endl;
    return 0;
}
