#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (char c : str) s.push(c);
    string res = "";
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int main() {
    string str = "GeeksforGeeks";
    cout << "Original: " << str << " | Reversed: " << reverseString(str) << endl;
    return 0;
}
