#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::string rearrangeString(const std::string& str) {
    int n = static_cast<int>(str.length());
    std::vector<int> count(26, 0);
    for (char c : str) {
        count[c - 'a']++;
    }

    std::priority_queue<std::pair<int, char>> pq;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            if (count[i] > (n + 1) / 2) return "";
            pq.push({count[i], static_cast<char>('a' + i)});
        }
    }

    std::string result;
    std::pair<int, char> prev = {-1, '#'};

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        result += current.second;

        if (prev.first > 0) {
            pq.push(prev);
        }

        current.first--;
        prev = current;
    }

    if (result.length() != str.length()) return "";
    return result;
}

int main() {
    std::string s1 = "aab";
    assert(rearrangeString(s1) == "aba");

    std::string s2 = "aaab";
    assert(rearrangeString(s2).empty());

    assert(rearrangeString("a") == "a");
    assert(rearrangeString("").empty());

    std::cout << "33_Rearrange_characters tests passed.\n";
    return 0;
}
