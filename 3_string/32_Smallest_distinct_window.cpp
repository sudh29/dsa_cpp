#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <string_view>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int findSubString(std::string_view str) {
        if (str.empty()) return 0;
        std::unordered_set<char> distinct(str.begin(), str.end());
        int total_distinct = static_cast<int>(distinct.size());

        std::vector<int> count(256, 0);
        int start = 0, min_len = INT_MAX, distinct_seen = 0;

        for (int end = 0; end < static_cast<int>(str.length()); end++) {
            if (count[static_cast<unsigned char>(str[end])] == 0) distinct_seen++;
            count[static_cast<unsigned char>(str[end])]++;

            while (distinct_seen == total_distinct) {
                min_len = std::min(min_len, end - start + 1);
                count[static_cast<unsigned char>(str[start])]--;
                if (count[static_cast<unsigned char>(str[start])] == 0) distinct_seen--;
                start++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    Solution sol;
    assert(sol.findSubString("aabcbcdbca") == 4);
    assert(sol.findSubString("aaab") == 2);
    assert(sol.findSubString("aaaa") == 1);
    assert(sol.findSubString("") == 0);

    std::cout << "32_Smallest_distinct_window tests passed.\n";
    return 0;
}
