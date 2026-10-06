#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int> &s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    sortedInsert(s, element);
    s.push(temp);
}

void sortStack(stack<int> &s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, temp);
    }
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    sortStack(s);
    cout << "Sorted stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
