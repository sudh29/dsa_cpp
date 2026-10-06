#include <iostream>
#include <bit>
#include <bitset>
#include <cassert>
#include <vector>

// Brian Kernighan's Algorithm: O(number of set bits)
constexpr unsigned int count_set_bits_kernighan(unsigned int n) noexcept {
    unsigned int count = 0;
    while (n > 0) {
        n &= (n - 1);
        ++count;
    }
    return count;
}

int main() {
    std::cout << "=== Counting Set Bits (Hamming Weight) in C++20 ===\n";

    const std::vector<unsigned int> test_cases = {0, 1, 5, 7, 15, 1023, 1024, 0xFFFFFFFFU};

    for (unsigned int val : test_cases) {
        unsigned int kernighan_cnt = count_set_bits_kernighan(val);
        int popcount_cnt = std::popcount(val);
        size_t bitset_cnt = std::bitset<32>(val).count();

        std::cout << "Value: " << val << " (0x" << std::hex << val << std::dec << ") "
                  << "-> Kernighan: " << kernighan_cnt
                  << ", std::popcount: " << popcount_cnt
                  << ", std::bitset: " << bitset_cnt << "\n";

        assert(kernighan_cnt == static_cast<unsigned int>(popcount_cnt));
        assert(kernighan_cnt == static_cast<unsigned int>(bitset_cnt));
    }

    // Compile-time verification
    static_assert(count_set_bits_kernighan(0) == 0);
    static_assert(count_set_bits_kernighan(7) == 3);
    static_assert(count_set_bits_kernighan(1023) == 10);

    std::cout << "All set bit tests passed!\n";
    return 0;
}
