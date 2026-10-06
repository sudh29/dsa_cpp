#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool ispar(string x) {
        stack<char> s;
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
    string s1 = "{([])}";
    string s2 = "([)]";
    cout << s1 << ": " << (sol.ispar(s1) ? "Balanced" : "Not Balanced") << endl;
    cout << s2 << ": " << (sol.ispar(s2) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
