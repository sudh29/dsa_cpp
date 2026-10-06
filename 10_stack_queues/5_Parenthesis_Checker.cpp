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
            } else if (c == ')' || c == '}' || c == ']') {
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
    assert(!sol.ispar("([)]"));
    assert(sol.ispar("()"));
    assert(sol.ispar(""));
    assert(!sol.ispar("("));
    assert(!sol.ispar(")"));
    assert(!sol.ispar("({[}])"));

    std::cout << "10_stack_queues 5_Parenthesis_Checker: All tests passed.\n";
    return 0;
}
