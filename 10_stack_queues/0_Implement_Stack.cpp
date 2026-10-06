#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    int topIndex;
    int capacity;
    vector<int> arr;

public:
    Stack(int cap = 100) : topIndex(-1), capacity(cap), arr(cap) {}

    bool push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++topIndex] = x;
        return true;
    }

    int pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int peek() {
        if (topIndex < 0) return -1;
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex < 0;
    }

    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top after pop: " << s.peek() << endl;
    return 0;
}
