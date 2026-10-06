#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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
    std::cout << "Min chocolate diff: " << findMinDiff(A, A.size(), M) << " (expected 6)\n";
    return 0;
}
