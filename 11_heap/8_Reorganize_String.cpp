#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

class Solution {
public:
    std::string reorganizeString(std::string_view s) {
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        std::priority_queue<std::pair<int, char>> pq;
        for (const auto &[ch, count] : freq) {
            pq.push({count, ch});
        }

        std::string res;
        res.reserve(s.size());
        std::pair<int, char> prev = {-1, '#'};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.second;

            if (prev.first > 0) {
                pq.push(prev);
            }

            cur.first--;
            prev = cur;
        }

        return (res.length() == s.length()) ? res : "";
    }
};

int main() {
    Solution sol;
    std::string res1 = sol.reorganizeString("aab");
    assert(!res1.empty());
    assert(res1 == "aba");

    std::string res2 = sol.reorganizeString("aaab");
    assert(res2.empty()); // Impossible to reorganize without adjacent identical characters

    std::string res3 = sol.reorganizeString("vvvlo");
    assert(!res3.empty());
    for (size_t i = 1; i < res3.size(); ++i) {
        assert(res3[i] != res3[i - 1]);
    }

    std::cout << "11_heap 8_Reorganize_String: All tests passed.\n";
    return 0;
}
