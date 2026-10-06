#include <iostream>
#include <string>
#include <utility>

class User {
private:
    std::string fullName;
    int birthYear;

public:
    User(std::string name, int year)
        : fullName(std::move(name)), birthYear(year) {}

    int getAge(int currentYear = 2026) const {
        return currentYear - birthYear;
    }

    void displayInfo() const {
        std::cout << "User: " << fullName << " | Birth Year: " << birthYear
                  << " | Age: " << getAge() << std::endl;
    }
};

int main() {
    std::cout << "=== C++ Classes & Object-Oriented Programming ===" << std::endl;
    User u1("Alice Smith", 1995);
    User u2("Bob Johnson", 2001);

    u1.displayInfo();
    u2.displayInfo();
    return 0;
}
