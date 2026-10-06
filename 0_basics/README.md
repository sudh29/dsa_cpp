# 0_Basics: Modern C++ Fundamentals

This module covers core foundational programming constructs in modern C++ (C++20), focusing on memory management, RAII, pointers & references, object-oriented programming, and essential mathematical algorithms.

## Programs (16 C++20 Programs)

### Language Fundamentals & Mechanics
| File | Topic / Concept |
|------|-----------------|
| [cpp_hello_and_io.cpp](cpp_hello_and_io.cpp) | Standard streams (`std::cout`, `std::cin`), string streams |
| [cpp_syntax_and_types.cpp](cpp_syntax_and_types.cpp) | Fundamental types, `auto` deduction, `std::numeric_limits`, compile-time arithmetic |
| [cpp_spaceship_operator.cpp](cpp_spaceship_operator.cpp) | C++20 three-way comparison operator (`<=>`) |
| [cpp_references_and_functions.cpp](cpp_references_and_functions.cpp) | Pass-by-reference (`&`), lambdas, function composition |
| [system_details.cpp](system_details.cpp) | Compiler identification, `__cplusplus` standard version |

### Memory Management & Data Organization
| File | Topic / Concept |
|------|-----------------|
| [cpp_pointers_and_memory.cpp](cpp_pointers_and_memory.cpp) | Raw pointers vs references, smart pointers (`std::unique_ptr`, `std::shared_ptr`), RAII |
| [cpp_structs_and_typedefs.cpp](cpp_structs_and_typedefs.cpp) | Structs vs classes, modern type aliases (`using`), structured bindings |
| [cpp_classes_and_oop.cpp](cpp_classes_and_oop.cpp) | Classes, constructors, encapsulation, const-correctness |
| [cpp_stl_containers.cpp](cpp_stl_containers.cpp) | `std::vector`, `std::unordered_map`, `std::unordered_set` |
| [cpp_file_io.cpp](cpp_file_io.cpp) | File stream processing with `std::ifstream` and `std::ofstream` |

### Algorithmic & Mathematical Fundamentals
| File | Topic / Concept |
|------|-----------------|
| [count_set_bits.cpp](count_set_bits.cpp) | Brian Kernighan's bit algorithm, C++20 `std::popcount`, `std::bitset` |
| [prime_check.cpp](prime_check.cpp) | Optimized trial division ($O(\sqrt{n})$) with `constexpr` & compile-time assertions |
| [swap_two_numbers.cpp](swap_two_numbers.cpp) | Swapping via references, move semantics (`std::move`), XOR, and `std::swap` |
| [cpp_anagrams.cpp](cpp_anagrams.cpp) | Anagram validation using frequency hashing |
| [cpp_pattern_count.cpp](cpp_pattern_count.cpp) | Substring search and pattern occurrence counting |
| [cpp_grid_paths.cpp](cpp_grid_paths.cpp) | Unique grid paths via Dynamic Programming |

## Compilation & Execution
```bash
# Compile and run any C++ program
g++ -std=c++20 -Wall -Wextra cpp_pointers_and_memory.cpp -o memory_demo && ./memory_demo
g++ -std=c++20 -Wall -Wextra count_set_bits.cpp -o count_bits && ./count_bits
```
