# 1_Array: Array Algorithms & Patterns

Complete C++20 implementations of the classic 35 array problems covering two-pointer techniques, sliding windows, interval manipulation, cycle detection, and greedy strategies.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_the_array.cpp](0_Reverse_the_array.cpp) | Two Pointer | In-place swapping ($O(n)$) |
| [1_Find_max_min_element_array.cpp](1_Find_max_min_element_array.cpp) | Linear Scan | Min/Max tracking in single pass |
| [2_Kth_smallest_element.cpp](2_Kth_smallest_element.cpp) | Selection | `std::nth_element` / QuickSelect |
| [3_Sort_an_array_of_0s,_1s_and_2s.cpp](3_Sort_an_array_of_0s,_1s_and_2s.cpp) | Dutch National Flag | 3-way partition in single pass |
| [4_Move_all_negative_elements_to_end.cpp](4_Move_all_negative_elements_to_end.cpp) | Two Pointer / Partition | Stable segregation of positive & negative |
| [5_Union_of_two_arrays.cpp](5_Union_of_two_arrays.cpp) | Hashing | `std::unordered_set` union counting |
| [6_Cyclically_rotate_an_array_by_one.cpp](6_Cyclically_rotate_an_array_by_one.cpp) | In-place Shift | Clockwise rotation by 1 |
| [7_Kadanes_Algorithm.cpp](7_Kadanes_Algorithm.cpp) | Dynamic Programming | Maximum contiguous subarray sum |
| [8_Minimize_the_Heights_II.cpp](8_Minimize_the_Heights_II.cpp) | Greedy | Height difference minimization after $\pm k$ |
| [9_Minimum_number_of_jumps.cpp](9_Minimum_number_of_jumps.cpp) | Greedy Jump | Tracking max reachable index |
| [10_Find_the_Duplicate_Number.cpp](10_Find_the_Duplicate_Number.cpp) | Cycle Detection | Floyd's Tortoise & Hare algorithm |
| [11_Merge_Without_Extra_Space.cpp](11_Merge_Without_Extra_Space.cpp) | Shell Sort Gap Method | In-place merging of two sorted arrays |
| [13_Merge_Intervals.cpp](13_Merge_Intervals.cpp) | Interval Greedy | Sorting intervals and merging overlaps |
| [14_Next_Permutation.cpp](14_Next_Permutation.cpp) | Permutation Logic | Finding lexicographically next permutation |
| [15_Count_Inversions.cpp](15_Count_Inversions.cpp) | Divide & Conquer | Enhanced Merge Sort inversion counter |
| [16_Best_Time_to_Buy_and_Sell_Stock.cpp](16_Best_Time_to_Buy_and_Sell_Stock.cpp) | Single Pass Greedy | Tracking rolling minimum price |
| [17_Count_pairs_with_given_sum.cpp](17_Count_pairs_with_given_sum.cpp) | Hash Map | Pair sum counting with complement map |
| [18_find_common_elements_In_3_sorted_arrays.cpp](18_find_common_elements_In_3_sorted_arrays.cpp) | Three Pointer | Intersection of 3 sorted arrays |
| [19_Alternate_positive_and_negative_numbers.cpp](19_Alternate_positive_and_negative_numbers.cpp) | Rearrangement | Interleaving positive and negative elements |
| [20_Subarray_with_0_sum.cpp](20_Subarray_with_0_sum.cpp) | Prefix Sum Hash Set | Detecting zero-sum subarrays |
| [21_Factorials_of_large_numbers.cpp](21_Factorials_of_large_numbers.cpp) | Big Int Simulation | Digit array multiplication for large factorials |
| [22_Maximum_Product_Subarray.cpp](22_Maximum_Product_Subarray.cpp) | Dynamic Programming | Tracking rolling min & max products |
| [23_Longest_consecutive_subsequence.cpp](23_Longest_consecutive_subsequence.cpp) | Hash Set | Longest sequence of consecutive integers |
| [24_Majority_Element_II_k_n.cpp](24_Majority_Element_II_k_n.cpp) | Frequency Map | Elements appearing $> n/k$ times |
| [25_Buy_and_Sell_Stock_III.cpp](25_Buy_and_Sell_Stock_III.cpp) | State Machine DP | Max profit with at most 2 transactions |
| [26_Array_Subset_of_another_array.cpp](26_Array_Subset_of_another_array.cpp) | Frequency Counting | Multiset inclusion validation |
| [27_Triplet_Sum_in_Array.cpp](27_Triplet_Sum_in_Array.cpp) | Sorting + Two Pointer | 3Sum exact target check |
| [28_Trapping_Rain_Water.cpp](28_Trapping_Rain_Water.cpp) | Two Pointer / Prefix Max | Calculating trapped water volume |
| [29_Chocolate_Distribution_Problem.cpp](29_Chocolate_Distribution_Problem.cpp) | Sliding Window | Minimizing difference in sorted packet window |
| [30_Minimum_Size_Subarray_Sum.cpp](30_Minimum_Size_Subarray_Sum.cpp) | Sliding Window | Smallest subarray with sum $\ge \text{target}$ |
| [31_Three_way_partitioning.cpp](31_Three_way_partitioning.cpp) | Dutch National Flag | Partitioning around a range $[a, b]$ |
| [32_Minimum_swaps_and_K_together.cpp](32_Minimum_swaps_and_K_together.cpp) | Sliding Window | Swapping elements $\le k$ into a contiguous block |
| [33_Form_a_palindrome.cpp](33_Form_a_palindrome.cpp) | Longest Palindromic Subsequence | Minimum insertions via DP |
| [34_Find_the_median.cpp](34_Find_the_median.cpp) | Sorting | Median of an odd/even sized array |
| [35_Median_of_2_Sorted_Arrays_of_Different_Sizes.cpp](35_Median_of_2_Sorted_Arrays_of_Different_Sizes.cpp) | Binary Search Partitioning | $O(\log(\min(n_1, n_2)))$ median across 2 arrays |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 7_Kadanes_Algorithm.cpp -o kadane && ./kadane
```
