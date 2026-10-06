#include <iostream>
#include <vector>

using namespace std;

class TwoStacks {
private:
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) : size(n), top1(-1), top2(n) {
        arr = new int[n];
    }

    ~TwoStacks() {
        delete[] arr;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    int pop1() {
        if (top1 >= 0) return arr[top1--];
        return -1;
    }

    int pop2() {
        if (top2 < size) return arr[top2++];
        return -1;
    }
};

int main() {
    TwoStacks ts(10);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);

    cout << "Popped from stack 1: " << ts.pop1() << endl;
    cout << "Popped from stack 2: " << ts.pop2() << endl;
    return 0;
}
