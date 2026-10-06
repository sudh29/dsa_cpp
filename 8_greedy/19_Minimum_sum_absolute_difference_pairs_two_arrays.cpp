#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    std::cout << "Min sum abs diff: " << findMinSum(A, B, A.size()) << " (expected 6)\n";
    return 0;
}
