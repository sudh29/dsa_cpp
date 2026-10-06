#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

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
    bool empty() const { return elements.empty(); }
    size_t size() const { return elements.size(); }
};

int main() {
    GenericStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("Modern");
    strStack.push("C++");

    while (!strStack.empty()) {
        std::cout << strStack.top() << " ";
        strStack.pop();
    }
    std::cout << std::endl;
    return 0;
}
