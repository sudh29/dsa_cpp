#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (mp.find(k - arr[i]) != mp.end()) {
                count += mp[k - arr[i]];
            }
            mp[arr[i]]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout << "Pairs with sum " << k << ": " << sol.getPairsCount(arr, n, k) << endl;
    return 0;
}
