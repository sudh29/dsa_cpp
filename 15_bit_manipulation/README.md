# 15_Bit_Manipulation: Bitwise Operations & Tricks

Complete C++20 implementations of fundamental bit manipulation algorithms, maskings, and bitwise arithmetic.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Number_of_1_Bits.cpp](0_Number_of_1_Bits.cpp) | Brian Kernighan | $O(\text{set bits})$ counting via $n \& (n-1)$ |
| [1_Non_Repeating_Numbers.cpp](1_Non_Repeating_Numbers.cpp) | 2 Unique Elements | XOR partition by rightmost set bit ($x \& (-x)$) |
| [2_Bit_Difference.cpp](2_Bit_Difference.cpp) | Hamming Distance | `__builtin_popcount(a ^ b)` |
| [3_Count_total_set_bits.cpp](3_Count_total_set_bits.cpp) | MSB Power Partition | Recursive counting in range $[1, n]$ |
| [4_Is_power_of_two.cpp](4_Is_power_of_two.cpp) | Bitwise AND | Single bit validation $(n \& (n - 1)) == 0$ |
| [5_Find_position_of_the_only_set_bit.cpp](5_Find_position_of_the_only_set_bit.cpp) | Bit Scanning | Locating index of lone set bit |
| [6_Set_all_the_bits_in_given_range_of_a_number.cpp](6_Set_all_the_bits_in_given_range_of_a_number.cpp) | Bit Masking | Range mask creation: $((1 \ll R) - 1) \oplus ((1 \ll (L - 1)) - 1)$ |
| [7_Division_without_using_multiplication_division_and_mod_operator.cpp](7_Division_without_using_multiplication_division_and_mod_operator.cpp) | Bitwise Long Division | Subtracting divisor shifted by $2^i$ |
| [8_Calculate_square_of_a_number_without_using_*_pow.cpp](8_Calculate_square_of_a_number_without_using_*_pow.cpp) | Bit Shifting | Odd/even decomposition: $(2x+1)^2 = 4(x^2+x)+1$ |
| [9_Power_Set.cpp](9_Power_Set.cpp) | Bitmask Subsets | Iterating bitmasks from $1$ to $2^n-1$ |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 0_Number_of_1_Bits.cpp -o setbits && ./setbits
```
