#include <cassert>
#include <cstdint>
#include <iostream>
#include <stack>

class SpecialStack {
private:
    std::stack<int64_t> s;
    int64_t minEle;

public:
    void push(int x) {
        int64_t val = x;
        if (s.empty()) {
            minEle = val;
            s.push(val);
        } else if (val < minEle) {
            s.push(2 * val - minEle);
            minEle = val;
        } else {
            s.push(val);
        }
    }

    int pop() {
        if (s.empty()) return -1;
        int64_t t = s.top();
        s.pop();
        if (t < minEle) {
            int64_t prevMin = minEle;
            minEle = 2 * minEle - t;
            return static_cast<int>(prevMin);
        }
        return static_cast<int>(t);
    }

    [[nodiscard]] int getMin() const {
        if (s.empty()) return -1;
        return static_cast<int>(minEle);
    }

    [[nodiscard]] bool empty() const {
        return s.empty();
    }
};

int main() {
    SpecialStack s;
    assert(s.empty());
    assert(s.getMin() == -1);

    s.push(18);
    assert(s.getMin() == 18);
    s.push(19);
    assert(s.getMin() == 18);
    s.push(29);
    assert(s.getMin() == 18);
    s.push(15);
    assert(s.getMin() == 15);
    s.push(16);
    assert(s.getMin() == 15);

    assert(s.pop() == 16);
    assert(s.getMin() == 15);

    assert(s.pop() == 15);
    assert(s.getMin() == 18);

    assert(s.pop() == 29);
    assert(s.pop() == 19);
    assert(s.pop() == 18);
    assert(s.empty());

    std::cout << "10_stack_queues 7_stack_that_supports_getMin_in_O1: All tests passed.\n";
    return 0;
}
