#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Dutch National Flag Algorithm
    void sort012(int a[], int n) {
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (a[mid] == 0) {
                swap(a[low++], a[mid++]);
            } else if (a[mid] == 1) {
                mid++;
            } else {
                swap(a[mid], a[high--]);
            }
        }
    }
};

int main() {
    Solution sol;
    int arr[] = {0, 2, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.sort012(arr, n);
    cout << "Sorted 0s 1s 2s: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
