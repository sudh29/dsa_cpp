#include <iostream>
#include <utility>
#include <climits>

using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    return make_pair(min_val, max_val);
}

int main() {
    long long arr[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto res = getMinMax(arr, n);
    cout << "Min: " << res.first << " | Max: " << res.second << endl;
    return 0;
}
