#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    std::string rearrangeString(std::string_view str) {
        std::unordered_map<char, int> freq;
        for (char c : str) freq[c]++;

        std::priority_queue<std::pair<int, char>> pq;
        for (const auto& [ch, count] : freq) pq.push({count, ch});

        std::string res;
        std::pair<int, char> prev = {-1, '#'};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.second;

            if (prev.first > 0) pq.push(prev);

            cur.first--;
            prev = cur;
        }

        if (res.length() != str.length()) return "";
        return res;
    }
};

static bool isValidRearrangement(std::string_view s) {
    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

int main() {
    Solution sol;
    std::string r1 = sol.rearrangeString("aaabc");
    assert(r1.length() == 5 && isValidRearrangement(r1));

    assert(sol.rearrangeString("aa") == "");
    assert(sol.rearrangeString("a") == "a");

    std::string r2 = sol.rearrangeString("aba");
    assert(r2.length() == 3 && isValidRearrangement(r2));

    std::cout << "33_Rearrange_characters_string_no_two_adjacent_are_same tests passed.\n";
    return 0;
}
