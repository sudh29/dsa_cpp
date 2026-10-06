#include <cassert>
#include <iostream>

/**
 * Topic: Compiler & System Architecture Verification
 * Module: 0_basics
 */

int main() {
    // Verify 64-bit architecture
    static_assert(sizeof(void*) == 8, "Expected 64-bit target");
    assert(sizeof(void*) == 8);

    // Verify C++20 standard compliance (202002L or newer)
    static_assert(__cplusplus >= 202002L, "Expected C++20 standard or newer");
    assert(__cplusplus >= 202002L);

    std::cout << "[PASS] 0_basics/system_details: all tests passed!\n";
    return 0;
}
