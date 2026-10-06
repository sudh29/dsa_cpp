# 11_Heap: Binary Heap & Priority Queue Algorithms

Complete C++20 implementations of Max-Heap, Min-Heap, priority queues, and classic streaming/median algorithms.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Implement_Maxheap_MinHeap_arrays_recursion.cpp](0_Implement_Maxheap_MinHeap_arrays_recursion.cpp) | Heap Construction | Recursive heapify & array heap builder |
| [1_Sort_Array_using_heap_sort.cpp](1_Sort_Array_using_heap_sort.cpp) | Sorting | In-place $O(n \log n)$ Heap Sort |
| [2_Maximum_all_subarrays_size_k.cpp](2_Maximum_all_subarrays_size_k.cpp) | Sliding Window | Monotonic deque / priority queue max tracker |
| [3_k_largest_element_array.cpp](3_k_largest_element_array.cpp) | Min-Heap Filter | Tracking $k$ largest via min-heap of size $k$ |
| [4_Kth_smallest_largest_element_unsorted_array.cpp](4_Kth_smallest_largest_element_unsorted_array.cpp) | Max-Heap Filter | Tracking $k$-th smallest element |
| [5_Merge_k_Sorted_Arrays.cpp](5_Merge_k_Sorted_Arrays.cpp) | K-Way Merge | Min-heap of size $k$ merging sorted row vectors |
| [6_Merge_2_Binary_Max_Heaps.cpp](6_Merge_2_Binary_Max_Heaps.cpp) | Array Concat & Heapify | Merging two arrays into a unified max-heap |
| [7_Kth_largest_sum_continuous_subarrays.cpp](7_Kth_largest_sum_continuous_subarrays.cpp) | Subarray Sums | Min-heap tracking top $k$ subarray sums |
| [8_Reorganize_String.cpp](8_Reorganize_String.cpp) | Greedy Max-Heap | Alternating character placement by frequency |
| [9_Merge_K_sorted_linked_lists.cpp](9_Merge_K_sorted_linked_lists.cpp) | K-Way Pointer Merge | Priority queue of list heads |
| [10_Smallest_range_in_K_lists.cpp](10_Smallest_range_in_K_lists.cpp) | Sliding Range | Tracking min & max across $K$ sorted streams |
| [11_Median_stream_Integers.cpp](11_Median_stream_Integers.cpp) | Dual Heaps | Balanced max-heap & min-heap for rolling median |
| [12_Is_Binary_Tree_Heap.cpp](12_Is_Binary_Tree_Heap.cpp) | Tree Validation | Completeness + parent $\ge$ child invariant |
| [13_Minimum_Cost_of_ropes.cpp](13_Minimum_Cost_of_ropes.cpp) | Huffman Greedy | Combining smallest two ropes with min-heap |
| [14_Convert_BST_to_Min_Max_Heap.cpp](14_Convert_BST_to_Min_Max_Heap.cpp) | Tree Traversal Order | Inorder to preorder conversion |
| [15_Convert_Min_Heap_Max_Heap.cpp](15_Convert_Min_Heap_Max_Heap.cpp) | Re-Heapify | Downward max-heapify from $(n-2)/2$ down to $0$ |
| [16_Rearrange_characters.cpp](16_Rearrange_characters.cpp) | Priority Queue | Adjacent distinct character rearrangement |
| [17_Minimum_sum.cpp](17_Minimum_sum.cpp) | Greedy Partition | Forming two numbers from sorted digits |
| [max_heap_fundamentals.cpp](max_heap_fundamentals.cpp) | Max-Heap Class | Custom dynamic max-heap class (`insert`, `extractMax`) |
| [min_heap_fundamentals.cpp](min_heap_fundamentals.cpp) | Min-Heap Class | Custom dynamic min-heap class (`insert`, `extractMin`) |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 11_Median_stream_Integers.cpp -o median && ./median
```
