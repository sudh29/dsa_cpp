#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>

class Solution {
public:
    std::string rearrangeString(std::string_view str) {
        std::unordered_map<char, int> freq;
        for (char c : str) {
            freq[c]++;
        }

        std::priority_queue<std::pair<int, char>> pq;
        for (const auto &[ch, cnt] : freq) {
            pq.push({cnt, ch});
        }

        std::string res;
        res.reserve(str.size());
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

        return (res.length() == str.length()) ? res : "-1";
    }
};

int main() {
    Solution sol;
    std::string res1 = sol.rearrangeString("geeksforgeeks");
    assert(res1 != "-1");
    assert(res1.length() == 13);
    for (size_t i = 1; i < res1.length(); ++i) {
        assert(res1[i] != res1[i - 1]);
    }

    std::string res2 = sol.rearrangeString("bbbbb");
    assert(res2 == "-1");

    std::cout << "11_heap 16_Rearrange_characters: All tests passed.\n";
    return 0;
}
