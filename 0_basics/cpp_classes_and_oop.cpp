#include <cassert>
#include <iostream>
#include <string>
#include <utility>

/**
 * Topic: C++ Classes & Object-Oriented Programming
 * Module: 0_basics
 */

class User {
private:
    std::string fullName;
    int birthYear;

public:
    User(std::string name, int year)
        : fullName(std::move(name)), birthYear(year) {}

    [[nodiscard]] const std::string& getName() const noexcept {
        return fullName;
    }

    [[nodiscard]] int getBirthYear() const noexcept {
        return birthYear;
    }

    [[nodiscard]] int getAge(int currentYear = 2026) const noexcept {
        return currentYear - birthYear;
    }
};

int main() {
    User u1("Alice Smith", 1995);
    User u2("Bob Johnson", 2001);

    assert(u1.getName() == "Alice Smith");
    assert(u1.getBirthYear() == 1995);
    assert(u1.getAge(2026) == 31);

    assert(u2.getName() == "Bob Johnson");
    assert(u2.getBirthYear() == 2001);
    assert(u2.getAge(2026) == 25);

    std::cout << "[PASS] 0_basics/cpp_classes_and_oop: all tests passed!\n";
    return 0;
}
