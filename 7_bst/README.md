# 7_BST: Binary Search Tree & Self-Balancing Trees

Complete C++20 implementations of Binary Search Tree algorithms, predecessor/successor lookups, interval conflicts, balancing, and AVL Tree self-balancing rotations.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Find_value_BST.cpp](0_Find_value_BST.cpp) | Search | Logarithmic traversal on BST invariant ($O(h)$) |
| [1_Deletion_node_BST.cpp](1_Deletion_node_BST.cpp) | Deletion | 0, 1, and 2-child cases using inorder successor |
| [2_Find_min_and_max_value_BST.cpp](2_Find_min_and_max_value_BST.cpp) | Min/Max Extremes | Extreme left and right pointer traversals |
| [3_Find_inorder_successor_and_inorder_predecessor_BST.cpp](3_Find_inorder_successor_and_inorder_predecessor_BST.cpp) | Predecessor/Successor | Inorder navigation without extra memory |
| [4_Check_if_tree_BST_or_not.cpp](4_Check_if_tree_BST_or_not.cpp) | Range Validation | Bounding subtrees with $(\text{min}, \text{max})$ |
| [5_Populate_Inorder_successor_all_nodes.cpp](5_Populate_Inorder_successor_all_nodes.cpp) | Reverse Inorder | Setting `next` pointer in reverse inorder |
| [6_Find_LCA_2_nodes_BST.cpp](6_Find_LCA_2_nodes_BST.cpp) | Lowest Common Ancestor | Divergence point of $n_1$ and $n_2$ |
| [7_Construct_BST_from_preorder_traversal.cpp](7_Construct_BST_from_preorder_traversal.cpp) | Construction | Upper-bound recursion in $O(n)$ |
| [8_Convert_Binary_tree_into_BST.cpp](8_Convert_Binary_tree_into_BST.cpp) | Inorder Sorting | Preserving tree topology while ordering keys |
| [9_Convert_normal_BST_into_Balanced_BST.cpp](9_Convert_normal_BST_into_Balanced_BST.cpp) | D&C Balancing | Rebuilding balanced tree from inorder array |
| [10_Merge_two_BST.cpp](10_Merge_two_BST.cpp) | Two Pointer Merge | Merging inorder traversals of two BSTs |
| [11_Find_Kth_largest_element_BST.cpp](11_Find_Kth_largest_element_BST.cpp) | Reverse Inorder | Reverse traversal with step count $k$ |
| [12_Find_Kth_smallest_element_BST.cpp](12_Find_Kth_smallest_element_BST.cpp) | Inorder Traversal | Standard inorder counting to $k$ |
| [13_Count_pairs_from_2_BST_sum_equal_X.cpp](13_Count_pairs_from_2_BST_sum_equal_X.cpp) | Hash Set Complement | Matching nodes across two independent trees |
| [14_Find_the_median_BST.cpp](14_Find_the_median_BST.cpp) | Median | Median value of sorted inorder sequence |
| [15_Count_BST_nodes_lie_range.cpp](15_Count_BST_nodes_lie_range.cpp) | Range Pruning | Pruning subtrees outside $[L, R]$ |
| [16_Replace_every_element_least_greater_element_right.cpp](16_Replace_every_element_least_greater_element_right.cpp) | BST Insertion Tracking | Predecessor/successor retrieval during build |
| [17_Given_n_appointments_find_conflicting_appointments.cpp](17_Given_n_appointments_find_conflicting_appointments.cpp) | Interval Sort & Scan | Detecting overlapping appointment intervals |
| [18_Check_preorder_valid_not.cpp](18_Check_preorder_valid_not.cpp) | Monotonic Stack | Validating preorder sequence of a BST |
| [19_Check_whether_BST_contains_Dead_end.cpp](19_Check_whether_BST_contains_Dead_end.cpp) | Hash Sets | Checking leaves bounded by $val-1$ and $val+1$ |
| [20_Largest_BST_Binary_Tree.cpp](20_Largest_BST_Binary_Tree.cpp) | Bottom-Up Tree DP | Finding max size valid BST subtree in $O(n)$ |
| [21_Flatten_BST_sorted_list.cpp](21_Flatten_BST_sorted_list.cpp) | Relinking | Transforming BST into sorted right-skewed list |
| [22_AVL_Tree_Operations.cpp](22_AVL_Tree_Operations.cpp) | Self-Balancing | LL, RR, LR, RL rotation implementations |
| [23_BST_Insert_Delete_Search.cpp](23_BST_Insert_Delete_Search.cpp) | BST Class ADT | Complete insertion, deletion, search operations |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 22_AVL_Tree_Operations.cpp -o avl && ./avl
```
