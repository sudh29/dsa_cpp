#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>

class Solution {
public:
    std::string FirstNonRepeating(std::string_view A) {
        std::array<int, 26> freq{};
        std::queue<char> q;
        std::string ans;
        ans.reserve(A.size());

        for (char c : A) {
            freq[static_cast<size_t>(c - 'a')]++;
            q.push(c);

            while (!q.empty() && freq[static_cast<size_t>(q.front() - 'a')] > 1) {
                q.pop();
            }

            if (q.empty()) {
                ans += '#';
            } else {
                ans += q.front();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.FirstNonRepeating("aabc") == "a#bb");
    assert(sol.FirstNonRepeating("zz") == "z#");
    assert(sol.FirstNonRepeating("abcde") == "aaaaa");

    std::cout << "10_stack_queues 36_First_non-repeating_character_in_a_stream: All tests passed.\n";
    return 0;
}
