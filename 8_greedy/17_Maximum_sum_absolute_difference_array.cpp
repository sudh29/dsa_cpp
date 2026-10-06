#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

long long maxSumPermutation(long long N) {
    if (N == 1) return 1;
    return (N * (N - 1)) / 2 + N / 2 - 1;
}

long long maxConsecutiveDiffSum(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    std::sort(arr.begin(), arr.end());
    std::vector<int> reordered;
    int i = 0, j = n - 1;
    while (i < j) {
        reordered.push_back(arr[i++]);
        reordered.push_back(arr[j--]);
    }
    if (i == j) reordered.push_back(arr[i]);

    long long sum = 0;
    for (int k = 0; k < n - 1; ++k) {
        sum += std::abs(reordered[k] - reordered[k + 1]);
    }
    sum += std::abs(reordered[n - 1] - reordered[0]);
    return sum;
}

int main() {
    assert(maxSumPermutation(4) == 7);
    assert(maxSumPermutation(1) == 1);

    std::vector<int> arr = {1, 2, 4, 8};
    assert(maxConsecutiveDiffSum(arr) == 18);

    std::cout << "17_Maximum_sum_absolute_difference_array tests passed.\n";
    return 0;
}
