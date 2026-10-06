#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Elements appearing more than n/k times
    vector<int> majorityElementK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size();
        for (int v : nums) count[v]++;

        vector<int> res;
        for (const auto &[val, freq] : count) {
            if (freq > n / k) {
                res.push_back(val);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    auto res = sol.majorityElementK(nums, k);
    cout << "Elements appearing > n/" << k << " times: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
