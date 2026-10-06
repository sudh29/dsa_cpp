#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

long long findMinDiff(std::vector<long long>& A, int N, int M) {
    if (M == 0 || N == 0 || M > N) return 0;
    std::sort(A.begin(), A.end());
    long long min_diff = LLONG_MAX;
    for (int i = 0; i + M - 1 < N; ++i) {
        long long diff = A[i + M - 1] - A[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    return min_diff;
}

int main() {
    std::vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    int M = 5;
    assert(findMinDiff(A, static_cast<int>(A.size()), M) == 6);

    std::vector<long long> A2 = {7, 3, 2, 4, 9, 12, 56};
    assert(findMinDiff(A2, static_cast<int>(A2.size()), 3) == 2);

    assert(findMinDiff(A, 0, 5) == 0);

    std::cout << "23_Chocolate_Distribution_Problem tests passed.\n";
    return 0;
}
