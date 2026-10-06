#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int plat_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            } else {
                plat_needed--;
                j++;
            }
            if (plat_needed > result) result = plat_needed;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Min platforms needed: " << sol.findPlatform(arr, dep, 6) << endl;
    return 0;
}
