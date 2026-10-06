#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

bool isValidString(const std::string& str) {
    int cnt = 0;
    for (char c : str) {
        if (c == '(') cnt++;
        else if (c == ')') cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

std::vector<std::string> removeInvalidParentheses(const std::string& str) {
    std::vector<std::string> res;
    if (str.empty()) return {""};

    std::unordered_set<std::string> visited;
    std::queue<std::string> q;

    q.push(str);
    visited.insert(str);
    bool found_valid_level = false;

    while (!q.empty()) {
        std::string curr = q.front();
        q.pop();

        if (isValidString(curr)) {
            res.push_back(curr);
            found_valid_level = true;
        }

        if (found_valid_level) continue;

        for (size_t i = 0; i < curr.length(); ++i) {
            if (curr[i] != '(' && curr[i] != ')') continue;
            std::string next_str = curr.substr(0, i) + curr.substr(i + 1);
            if (visited.find(next_str) == visited.end()) {
                visited.insert(next_str);
                q.push(next_str);
            }
        }
    }

    if (res.empty()) res.push_back("");
    return res;
}

int main() {
    std::string s = "()())()";
    auto valid = removeInvalidParentheses(s);
    assert(!valid.empty());
    for (const auto& v : valid) {
        assert(isValidString(v));
    }

    auto v2 = removeInvalidParentheses("()");
    assert(v2.size() == 1 && v2[0] == "()");

    auto v3 = removeInvalidParentheses(")(");
    assert(v3.size() == 1 && v3[0] == "");

    std::cout << "3_Remove_Invalid_Parentheses tests passed.\n";
    return 0;
}
