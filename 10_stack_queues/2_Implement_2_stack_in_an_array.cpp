#include <cassert>
#include <iostream>
#include <vector>

class TwoStacks {
private:
    int capacity;
    int top1;
    int top2;
    std::vector<int> arr;

public:
    explicit TwoStacks(int n) : capacity(n), top1(-1), top2(n), arr(n) {}

    bool push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
            return true;
        }
        return false;
    }

    bool push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
            return true;
        }
        return false;
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        }
        return -1;
    }

    int pop2() {
        if (top2 < capacity) {
            return arr[top2++];
        }
        return -1;
    }

    [[nodiscard]] bool empty1() const { return top1 < 0; }
    [[nodiscard]] bool empty2() const { return top2 >= capacity; }
};

int main() {
    TwoStacks ts(5);
    assert(ts.empty1());
    assert(ts.empty2());

    assert(ts.push1(5));
    assert(ts.push2(10));
    assert(ts.push2(15));
    assert(ts.push1(11));
    assert(ts.push2(7));
    // Now total elements = 5 (capacity full)
    assert(!ts.push1(99));
    assert(!ts.push2(99));

    assert(ts.pop1() == 11);
    assert(ts.pop2() == 7);
    assert(ts.pop2() == 15);
    assert(ts.pop2() == 10);
    assert(ts.pop2() == -1); // empty
    assert(ts.pop1() == 5);
    assert(ts.pop1() == -1); // empty

    std::cout << "10_stack_queues 2_Implement_2_stack_in_an_array: All tests passed.\n";
    return 0;
}
