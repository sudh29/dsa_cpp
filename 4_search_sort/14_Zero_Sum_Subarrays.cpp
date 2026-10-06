#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using ll = long long;

class Solution {
public:
    ll findSubarray(vector<ll> arr, int n) {
        unordered_map<ll, ll> mp;
        ll sum = 0, count = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (mp.find(sum) != mp.end()) {
                count += mp[sum];
            }
            mp[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<ll> arr = {0, 0, 5, 5, 0, 0};
    cout << "Zero sum subarrays count: " << sol.findSubarray(arr, arr.size()) << endl;
    return 0;
}
