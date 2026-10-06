#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Gap Method (Shell Sort logic)
    int nextGap(int gap) {
        if (gap <= 1) return 0;
        return (gap / 2) + (gap % 2);
    }

    void merge(long long arr1[], long long arr2[], int n, int m) {
        int gap = nextGap(n + m);
        while (gap > 0) {
            int i = 0, j = gap;
            while (j < (n + m)) {
                if (j < n && arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                } else if (i < n && j >= n && arr1[i] > arr2[j - n]) {
                    swap(arr1[i], arr2[j - n]);
                } else if (i >= n && j >= n && arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
                i++;
                j++;
            }
            gap = nextGap(gap);
        }
    }
};

int main() {
    Solution sol;
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};
    sol.merge(arr1, arr2, 4, 5);
    cout << "Merged arr1: ";
    for (int v : arr1) cout << v << " ";
    cout << "\narr2: ";
    for (int v : arr2) cout << v << " ";
    cout << endl;
    return 0;
}
