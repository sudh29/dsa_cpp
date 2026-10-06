# 2_Matrix: 2D Grid & Matrix Algorithms

Complete C++20 implementations for classic 2D matrix manipulation, searches, and dynamic programming patterns.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Spirally_traversing_a_matrix.cpp](0_Spirally_traversing_a_matrix.cpp) | Simulation | Boundary-based spiral unwinding |
| [1_Search_a_2D_Matrix.cpp](1_Search_a_2D_Matrix.cpp) | Binary Search | Virtual 1D index mapping ($O(\log(mn))$) |
| [2_Median_in_a_row_wise_sorted_Matrix.cpp](2_Median_in_a_row_wise_sorted_Matrix.cpp) | Binary Search on Value | Counting smaller elements with `upper_bound` |
| [3_Row_with_max_1s.cpp](3_Row_with_max_1s.cpp) | Top-Right Traversal | Staircase scan from top-right in $O(m + n)$ |
| [4_Sorted_matrix.cpp](4_Sorted_matrix.cpp) | Flattening & Sort | Flatten matrix, sort, and reshape |
| [5_Maximum_size_rectangle.cpp](5_Maximum_size_rectangle.cpp) | Histogram Stack DP | Largest rectangle of 1s using monotonic stack |
| [6_Find_a_specific_pair_in_matrix.cpp](6_Find_a_specific_pair_in_matrix.cpp) | 2D Suffix Max DP | Finding max $\text{mat}[c][d] - \text{mat}[a][b]$ |
| [7_Rotate_by_90_degree_anti.cpp](7_Rotate_by_90_degree_anti.cpp) | In-place Matrix Math | Transposition followed by column reversal |
| [8_Kth_element_in_Matrix.cpp](8_Kth_element_in_Matrix.cpp) | Min-Heap | K-way merge using `std::priority_queue` |
| [9_Common_elements_in_all_rows_of_a_given_matrix.cpp](9_Common_elements_in_all_rows_of_a_given_matrix.cpp) | Hash Map | Tracking occurrences row-by-row |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 0_Spirally_traversing_a_matrix.cpp -o spiral && ./spiral
```
