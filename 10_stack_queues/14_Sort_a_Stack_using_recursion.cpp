#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

void sortedInsert(std::stack<int> &s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(temp);
}

void sortStack(std::stack<int> &s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
}

int main() {
    std::stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    sortStack(s);

    std::vector<int> popped;
    while (!s.empty()) {
        popped.push_back(s.top());
        s.pop();
    }
    // Top of sorted stack should be maximum (30, 18, 14, -3, -5)
    std::vector<int> expected = {30, 18, 14, -3, -5};
    assert(popped == expected);

    std::cout << "10_stack_queues 14_Sort_a_Stack_using_recursion: All tests passed.\n";
    return 0;
}
