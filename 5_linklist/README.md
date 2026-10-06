# 5_Linklist: Linked List Algorithms

Complete C++20 implementations of the classic 29 linked list problems covering singly linked lists, doubly linked lists, circular lists, intersection algorithms, cycle detection, and memory management.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_a_linked_list.cpp](0_Reverse_a_linked_list.cpp) | Pointer Reversal | Iterative 3-pointer list reversal ($O(n)$) |
| [1_Reverse_Linked_List_groups_given_size.cpp](1_Reverse_Linked_List_groups_given_size.cpp) | Chunk Reversal | Reversing $k$ elements recursively |
| [2_Detect_Loop_in_linked_list.cpp](2_Detect_Loop_in_linked_list.cpp) | Floyd's Cycle Finding | Slow and fast pointer collision |
| [3_Remove_loop_LL.cpp](3_Remove_loop_LL.cpp) | Cycle Breaking | Finding cycle length and resetting loop pointer |
| [4_Find_first_node_of_loop_LL.cpp](4_Find_first_node_of_loop_LL.cpp) | Cycle Inception | Locating entry node to cycle |
| [5_Remove_duplicate_element_from_sorted_LL.cpp](5_Remove_duplicate_element_from_sorted_LL.cpp) | Deduplication | Skipping consecutive equal values |
| [6_Remove_duplicates_from_an_unsorted_LL.cpp](6_Remove_duplicates_from_an_unsorted_LL.cpp) | Hash Set | Deleting seen values in single pass |
| [7_Move_last_element_to_front_LL.cpp](7_Move_last_element_to_front_LL.cpp) | Pointer Relinking | Tail detachment and head insertion |
| [8_Add_1_to_a_number_represented_LL.cpp](8_Add_1_to_a_number_represented_LL.cpp) | Arithmetic Traversal | Reverse, propagate carry, and re-reverse |
| [9_Add_two_numbers_represented_LL.cpp](9_Add_two_numbers_represented_LL.cpp) | Multi-digit Addition | Summing two digit lists with carry |
| [10_Intersection_of_two_sorted_LL.cpp](10_Intersection_of_two_sorted_LL.cpp) | Two Pointer | Merged intersection of sorted lists |
| [11_Intersection_Point_in_Y_Shapped_LL.cpp](11_Intersection_Point_in_Y_Shapped_LL.cpp) | Pointer Alignment | Equalizing path lengths to finding merge point |
| [14_Middle_of_the_LL.cpp](14_Middle_of_the_LL.cpp) | Tortoise & Hare | $O(n)$ single pass mid-node retrieval |
| [15_Check_If_Circular_LL.cpp](15_Check_If_Circular_LL.cpp) | Cycle Check | Verifying circular termination |
| [16_Split_a_Circular_LL_into_two_halves.cpp](16_Split_a_Circular_LL_into_two_halves.cpp) | Circular Partition | Splitting circular list at midpoint |
| [17_Check_if_LL_is_Palindrome.cpp](17_Check_if_LL_is_Palindrome.cpp) | Mid Reversal | Comparing first half with reversed second half |
| [18_Deletion_and_Reverse_LL.cpp](18_Deletion_and_Reverse_LL.cpp) | Circular LL Manipulation | Node deletion and reverse in circular LL |
| [19_Reverse_a_Doubly_LL.cpp](19_Reverse_a_Doubly_LL.cpp) | DLL Pointer Swap | Swapping `next` and `prev` pointers |
| [20_Find_pairs_with_given_sum_in_doubly_LL.cpp](20_Find_pairs_with_given_sum_in_doubly_LL.cpp) | DLL Two Pointer | Meeting pointers from head and tail in sorted DLL |
| [21_Count_triplets_in_a_sorted_doubly_LL.cpp](21_Count_triplets_in_a_sorted_doubly_LL.cpp) | DLL 3Sum | Finding triplets with given target sum |
| [23_Rotate_doubly_LL.cpp](23_Rotate_doubly_LL.cpp) | DLL Block Shift | Rotating doubly linked list by $p$ nodes |
| [27_Flattening_a_LL.cpp](27_Flattening_a_LL.cpp) | Multilevel Merge | Merging 2D bottom-linked structures |
| [28_Sort_a_LL_of_0s_1s_and_2s.cpp](28_Sort_a_LL_of_0s_1s_and_2s.cpp) | Counting Sort | In-place value rewriting based on frequencies |
| [31_Multiply_two_LL.cpp](31_Multiply_two_LL.cpp) | Big Number Math | Modular arithmetic product of two list numbers |
| [32_Delete_nodes_having_greater_value_on_right_LL.cpp](32_Delete_nodes_having_greater_value_on_right_LL.cpp) | Suffix Max | Monotonic non-decreasing rightward filtering |
| [33_Segregate_even_and_odd_nodes_in_a_LL.cpp](33_Segregate_even_and_odd_nodes_in_a_LL.cpp) | Stable Partition | Appending even and odd nodes to separate tails |
| [34_Nth_node_from_end_of_LL.cpp](34_Nth_node_from_end_of_LL.cpp) | Fast/Slow Offset | Gap of $n$ nodes to track end distance |
| [35_First_non-repeating_character_in_a_stream.cpp](35_First_non-repeating_character_in_a_stream.cpp) | Queue Stream | Character frequency queue tracking |
| [LinkList1.cpp](LinkList1.cpp) | Linked List ADT | Complete C++ class implementation |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 0_Reverse_a_linked_list.cpp -o reverse && ./reverse
```
