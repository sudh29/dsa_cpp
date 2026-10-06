#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::cout << "=== Modern C++ Hello & I/O Streams ===" << std::endl;
    std::string greeting = "Hello from DSA C++!";
    std::cout << greeting << std::endl;

    // String Streams
    std::stringstream ss;
    int year = 2026;
    ss << "Year: " << year << " | Status: Ready";
    std::string formatted = ss.str();
    std::cout << formatted << std::endl;
    return 0;
}
