#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evaluatePostfix(string S) {
        stack<int> s;
        for (char c : S) {
            if (isdigit(c)) {
                s.push(c - '0');
            } else {
                int val1 = s.top(); s.pop();
                int val2 = s.top(); s.pop();
                switch (c) {
                    case '+': s.push(val2 + val1); break;
                    case '-': s.push(val2 - val1); break;
                    case '*': s.push(val2 * val1); break;
                    case '/': s.push(val2 / val1); break;
                }
            }
        }
        return s.top();
    }
};

int main() {
    Solution sol;
    string exp = "231*+9-";
    cout << "Evaluation of postfix " << exp << ": " << sol.evaluatePostfix(exp) << endl;
    return 0;
}
