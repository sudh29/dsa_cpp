#include <cassert>
#include <iostream>
#include <vector>

class Stack {
private:
    int topIndex;
    int capacity;
    std::vector<int> arr;

public:
    explicit Stack(int cap = 100) : topIndex(-1), capacity(cap), arr(cap) {}

    bool push(int x) {
        if (topIndex >= capacity - 1) {
            return false;
        }
        arr[++topIndex] = x;
        return true;
    }

    int pop() {
        if (topIndex < 0) {
            return -1;
        }
        return arr[topIndex--];
    }

    [[nodiscard]] int peek() const {
        if (topIndex < 0) return -1;
        return arr[topIndex];
    }

    [[nodiscard]] bool isEmpty() const {
        return topIndex < 0;
    }

    [[nodiscard]] int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack s(5);
    assert(s.isEmpty());
    assert(s.size() == 0);
    assert(s.peek() == -1);

    assert(s.push(10));
    assert(s.push(20));
    assert(s.push(30));
    assert(s.size() == 3);
    assert(!s.isEmpty());
    assert(s.peek() == 30);

    assert(s.pop() == 30);
    assert(s.peek() == 20);
    assert(s.size() == 2);

    assert(s.push(40));
    assert(s.push(50));
    assert(s.push(60));
    assert(!s.push(70)); // Overflow at capacity 5

    assert(s.pop() == 60);
    assert(s.pop() == 50);
    assert(s.pop() == 40);
    assert(s.pop() == 20);
    assert(s.pop() == 10);
    assert(s.pop() == -1); // Underflow
    assert(s.isEmpty());

    std::cout << "10_stack_queues 0_Implement_Stack: All tests passed.\n";
    return 0;
}
