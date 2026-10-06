#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
    long long mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    return {mn, mx};
}

int main() {
    long long arr[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = getMinMax(arr, n);
    cout << "Min: " << res.first << " | Max: " << res.second << endl;
    return 0;
}
