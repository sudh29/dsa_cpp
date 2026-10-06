#include <iostream>
#include <string>
#include <cassert>

using StudentID = int; // Modern C++ alternative to typedef

struct Student {
    StudentID id{0};
    std::string name{};
    double score{0.0};

    [[nodiscard]] bool is_passing() const noexcept {
        return score >= 60.0;
    }
};

void print_student(const Student& s) {
    std::cout << "Student ID: " << s.id 
              << " | Name: " << s.name 
              << " | Score: " << s.score 
              << " | Status: " << (s.is_passing() ? "PASS" : "FAIL") << "\n";
}

int main() {
    std::cout << "=== Modern C++ Structs, Type Aliases & Structured Bindings ===\n";

    // Designated initializers & uniform initialization
    Student s1{.id = 101, .name = "Alice Smith", .score = 94.5};
    Student s2{102, "Bob Jones", 58.0};

    print_student(s1);
    print_student(s2);

    assert(s1.is_passing());
    assert(!s2.is_passing());

    // C++17/20 Structured bindings
    auto [id, name, score] = s1;
    assert(id == 101);
    assert(name == "Alice Smith");
    assert(score == 94.5);

    std::cout << "Structured binding unpacked: " << name << " (ID: " << id << ")\n";
    std::cout << "All struct and type alias tests passed!\n";
    return 0;
}
