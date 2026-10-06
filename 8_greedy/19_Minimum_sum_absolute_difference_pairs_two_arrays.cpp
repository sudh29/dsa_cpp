#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

long long findMinSum(std::vector<long long>& A, std::vector<long long>& B, int N) {
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += std::abs(A[i] - B[i]);
    }
    return sum;
}

int main() {
    std::vector<long long> A = {4, 1, 8, 7};
    std::vector<long long> B = {2, 3, 6, 5};
    assert(findMinSum(A, B, static_cast<int>(A.size())) == 6);

    std::vector<long long> A2 = {1};
    std::vector<long long> B2 = {5};
    assert(findMinSum(A2, B2, 1) == 4);

    std::cout << "19_Minimum_sum_absolute_difference_pairs_two_arrays tests passed.\n";
    return 0;
}
