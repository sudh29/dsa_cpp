#include <cassert>
#include <iostream>
#include <span>
#include <unordered_set>
#include <vector>

class Solution {
public:
    size_t doUnion(std::span<const int> a, std::span<const int> b) {
        std::unordered_set<int> s;
        for (int v : a) s.insert(v);
        for (int v : b) s.insert(v);
        return s.size();
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 2, 3};
    assert(sol.doUnion(a, b) == 5);

    std::vector<int> c = {85, 25, 1, 32, 54, 6};
    std::vector<int> d = {85, 2};
    assert(sol.doUnion(c, d) == 7);

    std::cout << "1_array 5_Union_of_two_arrays: All tests passed.\n";
    return 0;
}
