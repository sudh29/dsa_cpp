#include <cassert>
#include <iostream>
#include <span>
#include <vector>

class Solution {
public:
    std::vector<int> commonElements(std::span<const int> A, std::span<const int> B, std::span<const int> C) {
        size_t i = 0, j = 0, k = 0;
        std::vector<int> res;

        while (i < A.size() && j < B.size() && k < C.size()) {
            if (A[i] == B[j] && B[j] == C[k]) {
                if (res.empty() || res.back() != A[i]) {
                    res.push_back(A[i]);
                }
                i++; j++; k++;
            } else if (A[i] < B[j]) {
                i++;
            } else if (B[j] < C[k]) {
                j++;
            } else {
                k++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> A = {1, 5, 10, 20, 40, 80};
    std::vector<int> B = {6, 7, 20, 80, 100};
    std::vector<int> C = {3, 4, 15, 20, 30, 70, 80, 120};

    auto common = sol.commonElements(A, B, C);
    std::vector<int> expected = {20, 80};
    assert(common == expected);

    std::vector<int> D = {1, 2, 3};
    std::vector<int> E = {4, 5, 6};
    std::vector<int> F = {7, 8, 9};
    assert(sol.commonElements(D, E, F).empty());

    std::cout << "1_array 18_find_common_elements_In_3_sorted_arrays: All tests passed.\n";
    return 0;
}
