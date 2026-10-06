#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Topic: Modern C++ Hello & I/O Streams
 * Module: 0_basics
 */

int main() {
    std::string greeting = "Hello from DSA C++!";
    assert(!greeting.empty());
    assert(greeting.length() == 19);

    std::stringstream ss;
    int year = 2026;
    ss << "Year: " << year << " | Status: Ready";
    std::string formatted = ss.str();

    assert(formatted == "Year: 2026 | Status: Ready");

    std::cout << "[PASS] 0_basics/cpp_hello_and_io: all tests passed!\n";
    return 0;
}
