#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int maxEqualSum(const std::vector<int>& S1, const std::vector<int>& S2, const std::vector<int>& S3) {
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    for (int x : S1) sum1 += x;
    for (int x : S2) sum2 += x;
    for (int x : S3) sum3 += x;

    size_t i = 0, j = 0, k = 0;
    while (i < S1.size() && j < S2.size() && k < S3.size()) {
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= S1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= S2[j++];
        } else {
            sum3 -= S3[k++];
        }
    }
    return 0;
}

int main() {
    std::vector<int> S1 = {4, 2, 3};
    std::vector<int> S2 = {1, 1, 2, 3};
    std::vector<int> S3 = {1, 4};
    std::cout << "Max equal sum: " << maxEqualSum(S1, S2, S3) << " (expected 5)\n";

    std::vector<int> A1 = {3, 2, 1, 1, 1};
    std::vector<int> A2 = {4, 3, 2};
    std::vector<int> A3 = {1, 1, 4, 1};
    std::cout << "Max equal sum: " << maxEqualSum(A1, A2, A3) << " (expected 5)\n";
    return 0;
}
