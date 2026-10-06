#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }

    void sortBySetBitCount(int arr[], int n) {
        stable_sort(arr, arr + n, comp);
    }
};

int main() {
    Solution sol;
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.sortBySetBitCount(arr, n);
    cout << "Sorted by set bit count: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
