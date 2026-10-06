#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long trappingWater(int arr[], int n) {
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        long long water = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= maxLeft) maxLeft = arr[left];
                else water += (maxLeft - arr[left]);
                left++;
            } else {
                if (arr[right] >= maxRight) maxRight = arr[right];
                else water += (maxRight - arr[right]);
                right--;
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Trapped rain water: " << sol.trappingWater(arr, n) << endl;
    return 0;
}
