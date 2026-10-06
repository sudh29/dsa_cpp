#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cassert>

void demonstrate_raw_pointers_and_references() {
    int x = 100;
    int* ptr = &x;
    int& ref = x;

    assert(*ptr == 100);
    assert(ref == 100);

    *ptr = 250;
    assert(x == 250);
    assert(ref == 250);

    ref = 500;
    assert(x == 500);
    assert(*ptr == 500);
}

void demonstrate_smart_pointers() {
    // std::unique_ptr (Exclusive ownership with RAII)
    auto u_ptr = std::make_unique<int>(42);
    assert(*u_ptr == 42);

    // Dynamic array via unique_ptr
    auto arr = std::make_unique<int[]>(5);
    for (int i = 0; i < 5; ++i) {
        arr[i] = (i + 1) * 10;
    }
    assert(arr[0] == 10 && arr[4] == 50);

    // std::shared_ptr (Shared ownership)
    auto s1 = std::make_shared<std::string>("Modern C++ Memory");
    {
        auto s2 = s1;
        assert(s1.use_count() == 2);
    }
    assert(s1.use_count() == 1);
}

void demonstrate_vector_dynamic_memory() {
    // std::vector handles dynamic resizing, heap allocation, and automatic deallocation
    std::vector<int> nums = {10, 20, 30, 40, 50};
    nums.push_back(60);
    assert(nums.size() == 6);
    assert(nums.front() == 10 && nums.back() == 60);
}

int main() {
    std::cout << "=== Modern C++ Pointers, References & RAII Memory Management ===\n";

    demonstrate_raw_pointers_and_references();
    std::cout << "Raw pointers and references: OK\n";

    demonstrate_smart_pointers();
    std::cout << "Smart pointers (unique_ptr, shared_ptr): OK\n";

    demonstrate_vector_dynamic_memory();
    std::cout << "Dynamic memory via std::vector: OK\n";

    std::cout << "All memory management demonstrations verified!\n";
    return 0;
}
