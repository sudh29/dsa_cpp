# 4_Search_Sort: Searching & Sorting Algorithms

Complete implementations of classic sorting algorithms and search/sort problem solutions in **modern C++ (C++20)**.

## Sorting Algorithms (C++20)
| Algorithm | C++ (C++20) Implementation | Time Complexity (Avg / Worst) | Space Complexity |
|-----------|----------------------------|-------------------------------|------------------|
| Bubble Sort | [bubble_sort.cpp](bubble_sort.cpp) | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| Selection Sort | [selection_sort.cpp](selection_sort.cpp) | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| Insertion Sort | [insertion_sort.cpp](insertion_sort.cpp) | $O(n^2)$ / $O(n^2)$ | $O(1)$ |
| Merge Sort | [merge_sort.cpp](merge_sort.cpp) | $O(n \log n)$ / $O(n \log n)$ | $O(n)$ |
| Quick Sort | [quick_sort.cpp](quick_sort.cpp) | $O(n \log n)$ / $O(n^2)$ | $O(\log n)$ |
| Heap Sort | [heap_sort.cpp](heap_sort.cpp) | $O(n \log n)$ / $O(n \log n)$ | $O(1)$ |

## Searching & Sorting Problems (C++20)
| File | Problem Description / Pattern |
|------|--------------------------------|
| [0_First_and_last_occurrences_of_x.cpp](0_First_and_last_occurrences_of_x.cpp) | Binary Search (First/Last Occurrence) |
| [1_Value_equal_to_index_value.cpp](1_Value_equal_to_index_value.cpp) | Linear Traversal / 1-based indexing |
| [2_Search_in_a_rotated_sorted_array.cpp](2_Search_in_a_rotated_sorted_array.cpp) | Modified Binary Search on Rotated Array |
| [3_Count_Squares.cpp](3_Count_Squares.cpp) | Integer square root counting |
| [4_Find_min_and_max_element_in_an_array.cpp](4_Find_min_and_max_element_in_an_array.cpp) | Min/Max element extraction |
| [6_Find_Missing_And_Repeating.cpp](6_Find_Missing_And_Repeating.cpp) | In-place array negation / Index mapping |
| [7_Majority_Element.cpp](7_Majority_Element.cpp) | Boyer-Moore Voting Algorithm |
| [8_Searching_in_an_array_where_adjacent_differ_by_at_most_k.cpp](8_Searching_in_an_array_where_adjacent_differ_by_at_most_k.cpp) | Step Jump Search ($O(n/k)$) |
| [9_Find_Pair_Given_Difference.cpp](9_Find_Pair_Given_Difference.cpp) | Sorting + Two Pointers |
| [10_Find_All_Four_Sum_Numbers.cpp](10_Find_All_Four_Sum_Numbers.cpp) | 4Sum with Two Pointers & Duplicate Avoidance |
| [11_maximum_sum_such_that_no_2_elements_are_adjacent.cpp](11_maximum_sum_such_that_no_2_elements_are_adjacent.cpp) | House Robber / DP without Adjacent |
| [12_Count_triplets_with_sum_smaller_than_X.cpp](12_Count_triplets_with_sum_smaller_than_X.cpp) | Two Pointer Triplet Counting |
| [13_merge_two_sorted_arrays.cpp](13_merge_two_sorted_arrays.cpp) | Merge procedure of two sorted arrays |
| [14_Zero_Sum_Subarrays.cpp](14_Zero_Sum_Subarrays.cpp) | Prefix Sum Hash Map counting |
| [15_Product_array_puzzle.cpp](15_Product_array_puzzle.cpp) | Prefix and Suffix product accumulators |
| [16_Sort_by_Set_Bit_Count.cpp](16_Sort_by_Set_Bit_Count.cpp) | `stable_sort` with `__builtin_popcount` |
| [17_Minimum_Swaps_to_Sort.cpp](17_Minimum_Swaps_to_Sort.cpp) | Graph Cycle Decomposition |
| [18_Bishu_and_Soldiers.cpp](18_Bishu_and_Soldiers.cpp) | `upper_bound` Binary Search + Prefix Sum |
| [20_Kth_smallest_number_again.cpp](20_Kth_smallest_number_again.cpp) | Interval Merging & k-th query resolution |
| [21_Find_pivot_element_in_a_sorted_array.cpp](21_Find_pivot_element_in_a_sorted_array.cpp) | Binary Search for Inflection Point |
| [22_Kth_element_of_two_sorted_Arrays.cpp](22_Kth_element_of_two_sorted_Arrays.cpp) | Binary Search Partitioning on Two Arrays |
| [23_Aggressive_cows.cpp](23_Aggressive_cows.cpp) | Binary Search on Answer (Min distance placement) |
| [26_Job_Scheduling_Algo.cpp](26_Job_Scheduling_Algo.cpp) | Greedy Deadline Slotting |
| [27_Arithmetic_Number.cpp](27_Arithmetic_Number.cpp) | Arithmetic Progression arithmetic check |
| [28_Smallest_factorial_number.cpp](28_Smallest_factorial_number.cpp) | Binary Search on Legendre's trailing zeros |
| [33_Count_Inversions.cpp](33_Count_Inversions.cpp) | Modified Merge Sort Inversion Counter |

## Compilation & Execution
```bash
# Compile a sorting algorithm
g++ -std=c++20 -Wall -Wextra -O2 bubble_sort.cpp -o bubble_cpp && ./bubble_cpp

# Compile a search problem
g++ -std=c++20 -Wall -Wextra -O2 2_Search_in_a_rotated_sorted_array.cpp -o search && ./search
```
