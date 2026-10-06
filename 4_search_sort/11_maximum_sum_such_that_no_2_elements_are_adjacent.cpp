#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int FindMaxSum(int arr[], int n) {
        if (n == 0) return 0;
        int incl = arr[0];
        int excl = 0;
        for (int i = 1; i < n; i++) {
            int new_excl = max(incl, excl);
            incl = excl + arr[i];
            excl = new_excl;
        }
        return max(incl, excl);
    }
};

int main() {
    Solution sol;
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Max sum without adjacent elements: " << sol.FindMaxSum(arr, n) << endl;
    return 0;
}
