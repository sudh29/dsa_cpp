#include <cassert>
#include <iostream>
#include <span>
#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int checkMirrorTree(int n, int e, std::span<const int> A, std::span<const int> B) {
        (void)n;
        assert(A.size() == static_cast<size_t>(2 * e));
        assert(B.size() == static_cast<size_t>(2 * e));

        std::unordered_map<int, std::stack<int>> mp;
        for (size_t i = 0; i < static_cast<size_t>(2 * e); i += 2) {
            mp[A[i]].push(A[i + 1]);
        }
        for (size_t i = 0; i < static_cast<size_t>(2 * e); i += 2) {
            if (mp[B[i]].empty() || mp[B[i]].top() != B[i + 1]) {
                return 0;
            }
            mp[B[i]].pop();
        }
        return 1;
    }
};

int main() {
    std::vector<int> A = {1, 2, 1, 3};
    std::vector<int> B = {1, 3, 1, 2};
    Solution sol;
    assert(sol.checkMirrorTree(3, 2, A, B) == 1);

    std::vector<int> C = {1, 2, 1, 3};
    std::vector<int> D = {1, 2, 1, 3}; // Same order, not mirror
    assert(sol.checkMirrorTree(3, 2, C, D) == 0);

    std::cout << "6_binary_tree 24_Check_Mirror_N-ary_tree: All tests passed.\n";
    return 0;
}
