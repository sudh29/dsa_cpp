#include <cassert>
#include <cctype>
#include <iostream>
#include <stack>
#include <string_view>

class Solution {
public:
    int evaluatePostfix(std::string_view S) {
        std::stack<int> s;
        for (char c : S) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                s.push(c - '0');
            } else {
                assert(s.size() >= 2);
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();
                switch (c) {
                    case '+': s.push(val2 + val1); break;
                    case '-': s.push(val2 - val1); break;
                    case '*': s.push(val2 * val1); break;
                    case '/': 
                        assert(val1 != 0);
                        s.push(val2 / val1); 
                        break;
                    default: break;
                }
            }
        }
        assert(!s.empty());
        return s.top();
    }
};

int main() {
    Solution sol;
    assert(sol.evaluatePostfix("231*+9-") == -4);
    assert(sol.evaluatePostfix("123+*8-") == -3);

    std::cout << "10_stack_queues 11_Evaluation_of_Postfix_Expression: All tests passed.\n";
    return 0;
}
