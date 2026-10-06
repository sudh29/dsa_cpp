#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int> &arr, int n) {
        int repeating = -1, missing = -1;
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            if (arr[idx] < 0) {
                repeating = abs(arr[i]);
            } else {
                arr[idx] = -arr[idx];
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        return {repeating, missing};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 3};
    int n = arr.size();
    vector<int> res = sol.findTwoElement(arr, n);
    cout << "Repeating: " << res[0] << " | Missing: " << res[1] << endl;
    return 0;
}
