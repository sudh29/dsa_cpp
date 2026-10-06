#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <string_view>

std::string reverseString(std::string_view str) {
    std::stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    std::string res;
    res.reserve(str.size());
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int main() {
    assert(reverseString("GeeksforGeeks") == "skeeGrofskeeG");
    assert(reverseString("hello") == "olleh");
    assert(reverseString("a") == "a");
    assert(reverseString("").empty());

    std::cout << "10_stack_queues 6_Reverse_a_String_using_Stack: All tests passed.\n";
    return 0;
}
