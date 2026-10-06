#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        unordered_set<int> sumSet;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0 || sumSet.find(sum) != sumSet.end()) return true;
            sumSet.insert(sum);
        }
        return false;
    }
};

int main() {
    Solution sol;
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Subarray with 0 sum exists: " << (sol.subArrayExists(arr, n) ? "Yes" : "No") << endl;
    return 0;
}
