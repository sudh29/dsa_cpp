#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long maxSumPermutation(long long N) {
    if (N == 1) return 1;
    return (N * (N - 1)) / 2 + N / 2 - 1;
}

long long maxConsecutiveDiffSum(std::vector<int>& arr) {
    int n = arr.size();
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
    long long N = 4;
    std::cout << "Max sum for permutation 1..N (N=4): " << maxSumPermutation(N) << "\n";

    std::vector<int> arr = {1, 2, 4, 8};
    std::cout << "Max sum absolute diff (array {1, 2, 4, 8}): " << maxConsecutiveDiffSum(arr) << "\n";
    return 0;
}
