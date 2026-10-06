# 10_Stack_Queues: Stacks & Queues

Comprehensive implementations of Stack and Queue data structures and classic problems in **C++ (C++20)**.

## Problems & Implementations

| File | Data Structure / Pattern | Key Concept |
|------|--------------------------|-------------|
| [0_Implement_Stack.cpp](0_Implement_Stack.cpp) | Stack | Array-based fixed capacity stack (`push`, `pop`, `peek`) |
| [1_Implement_Queue.cpp](1_Implement_Queue.cpp) | Circular Queue | Array-based circular queue with modulo indexing |
| [2_Implement_2_stack_in_an_array.cpp](2_Implement_2_stack_in_an_array.cpp) | Space Optimization | 2 stacks growing towards each other in 1 array |
| [3_find_the_middle_element_of_a_stack.cpp](3_find_the_middle_element_of_a_stack.cpp) | Mid Tracking | Doubly linked list stack with $O(1)$ `findMiddle()` |
| [4_Implement_N_stacks_in_an_Array.cpp](4_Implement_N_stacks_in_an_Array.cpp) | Space-Efficient Design | $K$ stacks in an array of size $N$ using `next` array |
| [5_Parenthesis_Checker.cpp](5_Parenthesis_Checker.cpp) | Stack Pattern | Bracket balance validation using `std::stack` |
| [6_Reverse_a_String_using_Stack.cpp](6_Reverse_a_String_using_Stack.cpp) | LIFO Property | Reversing characters using stack |
| [7_stack_that_supports_getMin_in_O1.cpp](7_stack_that_supports_getMin_in_O1.cpp) | Auxiliary Math Min | Special stack supporting `getMin()` in $O(1)$ time & space |
| [8_Find_the_next_Greater_element.cpp](8_Find_the_next_Greater_element.cpp) | Monotonic Stack | Nearest greater element to the right |
| [11_Evaluation_of_Postfix_Expression.cpp](11_Evaluation_of_Postfix_Expression.cpp) | Arithmetic Parsing | Evaluating Reverse Polish Notation (RPN) |
| [14_Sort_a_Stack_using_recursion.cpp](14_Sort_a_Stack_using_recursion.cpp) | Pure Recursion | Sorting stack without loops or external data structures |
| [15_Merge_Overlapping_Intervals.cpp](15_Merge_Overlapping_Intervals.cpp) | Interval Greedy | Sorting and merging intervals |
| [36_First_non-repeating_character_in_a_stream.cpp](36_First_non-repeating_character_in_a_stream.cpp) | Queue Stream | Tracking first non-repeating character in stream |
| [stack_generic.cpp](stack_generic.cpp) | Modern C++ Template | Generic `Stack<T>` class template |
| [queue_generic.cpp](queue_generic.cpp) | Modern C++ Template | Generic `Queue<T>` class template |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 0_Implement_Stack.cpp -o stack && ./stack
g++ -std=c++20 -Wall -Wextra 8_Find_the_next_Greater_element.cpp -o nge && ./nge
```
