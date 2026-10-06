#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int maxEqualSum(const std::vector<int>& S1, const std::vector<int>& S2, const std::vector<int>& S3) {
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    for (int x : S1) sum1 += x;
    for (int x : S2) sum2 += x;
    for (int x : S3) sum3 += x;

    size_t i = 0, j = 0, k = 0;
    while (i < S1.size() && j < S2.size() && k < S3.size()) {
        if (sum1 == sum2 && sum2 == sum3) {
            return static_cast<int>(sum1);
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
    assert(maxEqualSum(S1, S2, S3) == 5);

    std::vector<int> A1 = {3, 2, 1, 1, 1};
    std::vector<int> A2 = {4, 3, 2};
    std::vector<int> A3 = {1, 1, 4, 1};
    assert(maxEqualSum(A1, A2, A3) == 5);

    assert(maxEqualSum({}, {}, {}) == 0);

    std::cout << "34_Find_Maximum_Equal_sum_Three_Stack tests passed.\n";
    return 0;
}
