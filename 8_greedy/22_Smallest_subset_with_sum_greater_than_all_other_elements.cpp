#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int minSubset(std::vector<int>& A, int N) {
    std::sort(A.begin(), A.end());
    long long total_sum = 0;
    for (int x : A) total_sum += x;

    long long curr_sum = 0;
    int count = 0;
    for (int i = N - 1; i >= 0; --i) {
        curr_sum += A[i];
        total_sum -= A[i];
        count++;
        if (curr_sum > total_sum) {
            return count;
        }
    }
    return count;
}

int main() {
    std::vector<int> A = {2, 17, 7, 3};
    std::cout << "Min subset size: " << minSubset(A, A.size()) << " (expected 1)\n";
    std::vector<int> B = {20, 12, 18, 4};
    std::cout << "Min subset size: " << minSubset(B, B.size()) << " (expected 2)\n";
    return 0;
}
