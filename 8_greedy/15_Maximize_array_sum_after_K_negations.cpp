#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

long long maximizeSum(std::vector<long long>& a, int n, int k) {
    std::sort(a.begin(), a.end());
    int i = 0;
    for (i = 0; i < n && k > 0; ++i) {
        if (a[i] < 0) {
            a[i] = -a[i];
            --k;
        } else {
            break;
        }
    }
    if (k > 0 && k % 2 == 1) {
        // Find element with minimum absolute value
        int min_idx = 0;
        for (int j = 1; j < n; ++j) {
            if (std::abs(a[j]) < std::abs(a[min_idx])) {
                min_idx = j;
            }
        }
        a[min_idx] = -a[min_idx];
    }
    long long sum = 0;
    for (int j = 0; j < n; ++j) sum += a[j];
    return sum;
}

int main() {
    std::vector<long long> arr1 = {-2, -3, 4, 1};
    int k1 = 2;
    std::cout << "Max sum after k=2: " << maximizeSum(arr1, arr1.size(), k1) << " (expected 10)\n";

    std::vector<long long> arr2 = {5, -2, 5, -4, 5, -12, 5, 5, 5, 20};
    int k2 = 5;
    std::cout << "Max sum after k=5: " << maximizeSum(arr2, arr2.size(), k2) << " (expected 68)\n";

    return 0;
}
