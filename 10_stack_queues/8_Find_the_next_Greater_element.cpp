#include <cassert>
#include <cstdint>
#include <iostream>
#include <span>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int64_t> nextLargerElement(std::span<const int64_t> arr) {
        size_t n = arr.size();
        std::vector<int64_t> res(n, -1);
        std::stack<int64_t> s;

        for (size_t i = n; i > 0; --i) {
            size_t idx = i - 1;
            while (!s.empty() && s.top() <= arr[idx]) {
                s.pop();
            }
            if (!s.empty()) {
                res[idx] = s.top();
            }
            s.push(arr[idx]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int64_t> arr1 = {1, 3, 2, 4};
    std::vector<int64_t> exp1 = {3, 4, 4, -1};
    assert(sol.nextLargerElement(arr1) == exp1);

    std::vector<int64_t> arr2 = {6, 8, 0, 1, 3};
    std::vector<int64_t> exp2 = {8, -1, 1, 3, -1};
    assert(sol.nextLargerElement(arr2) == exp2);

    std::cout << "10_stack_queues 8_Find_the_next_Greater_element: All tests passed.\n";
    return 0;
}
