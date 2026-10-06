#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> valueEqualToIndex(int arr[], int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (arr[i] == i + 1) { // 1-based indexing
                res.push_back(arr[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int arr[] = {15, 2, 45, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = sol.valueEqualToIndex(arr, n);
    cout << "Values equal to 1-based index: ";
    for (int v : res) cout << v << " ";
    cout << endl;
    return 0;
}
