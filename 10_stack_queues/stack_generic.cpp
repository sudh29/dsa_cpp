#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class GenericStack {
private:
    std::vector<T> elements;

public:
    void push(const T &val) { elements.push_back(val); }
    void pop() {
        if (elements.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
        elements.pop_back();
    }
    const T& top() const {
        if (elements.empty()) throw std::out_of_range("Stack<>::top(): empty stack");
        return elements.back();
    }
    [[nodiscard]] bool empty() const { return elements.empty(); }
    [[nodiscard]] size_t size() const { return elements.size(); }
};

int main() {
    GenericStack<std::string> strStack;
    assert(strStack.empty());
    assert(strStack.size() == 0);

    strStack.push("Hello");
    strStack.push("Modern");
    strStack.push("C++");
    assert(strStack.size() == 3);
    assert(!strStack.empty());
    assert(strStack.top() == "C++");

    strStack.pop();
    assert(strStack.top() == "Modern");
    strStack.pop();
    assert(strStack.top() == "Hello");
    strStack.pop();
    assert(strStack.empty());

    bool caught = false;
    try {
        strStack.pop();
    } catch (const std::out_of_range &) {
        caught = true;
    }
    assert(caught);

    std::cout << "10_stack_queues stack_generic: All tests passed.\n";
    return 0;
}
