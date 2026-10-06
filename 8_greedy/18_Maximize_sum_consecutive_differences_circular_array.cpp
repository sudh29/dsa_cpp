#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long maxSum(std::vector<int>& arr, int n) {
    std::sort(arr.begin(), arr.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += std::abs(arr[i] - arr[n - 1 - i]);
    }
    return res;
}

int main() {
    std::vector<int> arr = {4, 2, 1, 8};
    std::cout << "Max sum circular diff: " << maxSum(arr, arr.size()) << " (expected 18)\n";
    return 0;
}
