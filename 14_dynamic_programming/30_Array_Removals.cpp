#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int removals(std::vector<int>& arr, int n, int k) {
    std::sort(arr.begin(), arr.end());
    int min_removals = n - 1;
    int j = 0;

    for (int i = 0; i < n; ++i) {
        while (j < n && arr[j] - arr[i] <= k) {
            j++;
        }
        min_removals = std::min(min_removals, n - (j - i));
    }
    return min_removals;
}

int main() {
    std::vector<int> arr = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int k = 4;
    std::cout << "Min removals: " << removals(arr, arr.size(), k) << " (expected 5)\n";
    return 0;
}
