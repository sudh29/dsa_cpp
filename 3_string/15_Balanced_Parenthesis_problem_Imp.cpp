#include <cassert>
#include <iostream>
#include <stack>
#include <string_view>

class Solution {
public:
    bool ispar(std::string_view x) {
        std::stack<char> s;
        for (char c : x) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else {
                if (s.empty()) return false;
                char top = s.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

int main() {
    Solution sol;
    assert(sol.ispar("{([])}"));
    assert(sol.ispar("()"));
    assert(sol.ispar("()[]{}"));
    assert(!sol.ispar("([)]"));
    assert(!sol.ispar("]"));
    assert(!sol.ispar("((("));
    assert(sol.ispar(""));

    std::cout << "15_Balanced_Parenthesis_problem_Imp tests passed.\n";
    return 0;
}
