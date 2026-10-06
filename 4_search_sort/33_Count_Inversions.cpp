#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long merge(long long arr[], long long l, long long m, long long r) {
        long long ci = 0;
        long long i = l, j = m + 1, k = 0;
        vector<long long> temp(r - l + 1);

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                ci += (m - i + 1);
            }
        }
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (int p = 0; p < k; p++) arr[l + p] = temp[p];
        return ci;
    }

    long long mergesort(long long arr[], long long low, long long high) {
        long long ci = 0;
        if (low < high) {
            long long mid = low + (high - low) / 2;
            ci += mergesort(arr, low, mid);
            ci += mergesort(arr, mid + 1, high);
            ci += merge(arr, low, mid, high);
        }
        return ci;
    }

    long long int inversionCount(long long arr[], long long N) {
        return mergesort(arr, 0, N - 1);
    }
};

int main() {
    Solution sol;
    long long arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Inversion count: " << sol.inversionCount(arr, n) << endl;
    return 0;
}
