#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

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
    assert(minSubset(A, static_cast<int>(A.size())) == 1);

    std::vector<int> B = {20, 12, 18, 4};
    assert(minSubset(B, static_cast<int>(B.size())) == 2);

    std::cout << "22_Smallest_subset_with_sum_greater_than_all_other_elements tests passed.\n";
    return 0;
}
