#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

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
    std::cout << "Valid expressions for '" << s << "':\n";
    for (const auto& v : valid) {
        std::cout << "  " << v << "\n";
    }
    return 0;
}
