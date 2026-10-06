# 6_Binary_Tree: Binary Tree Algorithms

Complete C++20 implementations of the classic 41 binary tree problems covering traversals (level order, boundary, diagonal, zigzag), views (left, right, top, bottom), construction, transformations, LCA, and subtree dynamic programming.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Level_order_traversal.cpp](0_Level_order_traversal.cpp) | BFS Queue | Standard breadth-first level order traversal |
| [1_Reverse_Level_Order_traversal.cpp](1_Reverse_Level_Order_traversal.cpp) | Queue + Stack | Bottom-up level order traversal |
| [2_Height_of_a_tree.cpp](2_Height_of_a_tree.cpp) | Recursion | Max depth of binary tree ($1 + \max(lh, rh)$) |
| [3_Diameter_of_a_tree.cpp](3_Diameter_of_a_tree.cpp) | Tree DP | Longest path between two leaves in $O(n)$ |
| [4_Mirror_of_a_tree.cpp](4_Mirror_of_a_tree.cpp) | Invert Tree | Swapping left and right pointers recursively |
| [5_Inorder_Traversal.cpp](5_Inorder_Traversal.cpp) | Tree DFS | Left-Root-Right traversal |
| [6_Preorder_Traversal.cpp](6_Preorder_Traversal.cpp) | Tree DFS | Root-Left-Right traversal |
| [7_Postorder_Traversal.cpp](7_Postorder_Traversal.cpp) | Tree DFS | Left-Right-Root traversal |
| [8_Left_View_tree.cpp](8_Left_View_tree.cpp) | Level Tracking | First node visible from the left |
| [9_Right_View_Tree.cpp](9_Right_View_Tree.cpp) | Level Tracking | First node visible from the right |
| [10_Top_View_tree.cpp](10_Top_View_tree.cpp) | Horizontal Distance | First node at each horizontal offset using `std::map` |
| [11_Bottom_View_tree.cpp](11_Bottom_View_tree.cpp) | Horizontal Distance | Last node at each horizontal offset |
| [12_Zig_Zag_tree.cpp](12_Zig_Zag_tree.cpp) | Level Alternation | Reversing alternating levels in BFS |
| [13_Check_tree_balanced_or_not.cpp](13_Check_tree_balanced_or_not.cpp) | Height Balance | Height difference $\le 1$ at every node |
| [14_Diagonal_Traversal_tree.cpp](14_Diagonal_Traversal_tree.cpp) | Slope Traversal | Traversing right child chains via queue |
| [15_Boundary_traversal_tree.cpp](15_Boundary_traversal_tree.cpp) | Perimeter Walk | Left boundary + leaves + reverse right boundary |
| [16_Construct_Binary_Tree_String_Bracket_Representation.cpp](16_Construct_Binary_Tree_String_Bracket_Representation.cpp) | Parsing | Deserializing string bracket representation |
| [17_Convert_Binary_tree_Doubly_Linked_List.cpp](17_Convert_Binary_tree_Doubly_Linked_List.cpp) | In-place Relinking | Transforming binary tree into sorted DLL |
| [18_Convert_Binary_tree_Sum_tree.cpp](18_Convert_Binary_tree_Sum_tree.cpp) | Postorder Mutation | Node value replaced by sum of subtrees |
| [19_Construct_Binary_tree_from_Inorder_and_preorder_traversal.cpp](19_Construct_Binary_tree_from_Inorder_and_preorder_traversal.cpp) | D&C Reconstruction | Preorder root partition on Inorder hash map |
| [20_Find_minimum_swaps_required_convert_Binary_tree_into_BST.cpp](20_Find_minimum_swaps_required_convert_Binary_tree_into_BST.cpp) | Array Cycles | Minimum swaps to sort inorder array |
| [21_Check_if_Binary_tree_is_Sum_tree_or_not.cpp](21_Check_if_Binary_tree_is_Sum_tree_or_not.cpp) | Sum Validation | Verifying $node = left\_sum + right\_sum$ |
| [22_Leaf_at_same_leve.cpp](22_Leaf_at_same_leve.cpp) | Leaf Depth | Validating uniform depth across all leaves |
| [23_Check_Binary_Tree_duplicate_subtrees.cpp](23_Check_Binary_Tree_duplicate_subtrees.cpp) | Subtree Hashing | Finding duplicate subtrees of size $\ge 2$ |
| [24_Check_Mirror_N-ary_tree.cpp](24_Check_Mirror_N-ary_tree.cpp) | Stack Matching | Testing mirror symmetry across N-ary edges |
| [25_Sum_Nodes_Longest_path_from_root_leaf_node.cpp](25_Sum_Nodes_Longest_path_from_root_leaf_node.cpp) | Path Accumulation | Max sum along paths of maximum length |
| [26_Check_graph_tree_or_not.cpp](26_Check_graph_tree_or_not.cpp) | Graph Cycle & Connect | Cycle detection + single component check |
| [27_Find_Largest_subtree_sum_tree.cpp](27_Find_Largest_subtree_sum_tree.cpp) | Subtree DP | Maximum subtree node sum |
| [28_Maximum_Sum_nodes_Binary_tree_adjacent.cpp](28_Maximum_Sum_nodes_Binary_tree_adjacent.cpp) | Independent Set DP | House Robber III pattern on trees |
| [29_Print_all_K_Sum_paths_Binary_tree.cpp](29_Print_all_K_Sum_paths_Binary_tree.cpp) | Backtracking Path | Counting any downward path summing to $k$ |
| [30_Find_LCA_Binary_tree.cpp](30_Find_LCA_Binary_tree.cpp) | Lowest Common Ancestor | Divergence node in non-BST binary tree |
| [31_Find_distance_between_nodes_Binary_tree.cpp](31_Find_distance_between_nodes_Binary_tree.cpp) | LCA Distance | $dist(LCA, a) + dist(LCA, b)$ |
| [32_Kth_Ancestor_node_Binary_tree.cpp](32_Kth_Ancestor_node_Binary_tree.cpp) | Ancestor Tracing | Node at $k$ steps up from target |
| [33_Find_all_Duplicate_subtrees_Binary_tree.cpp](33_Find_all_Duplicate_subtrees_Binary_tree.cpp) | Tree Serialization | Hash serialization finding identical subtrees |
| [34_Tree_Isomorphism_Problem.cpp](34_Tree_Isomorphism_Problem.cpp) | Structural Isomorphism | Validating tree equality under child flips |
| [35_tree_traversals_all.cpp](35_tree_traversals_all.cpp) | Basic Traversals | Inorder, Preorder, Postorder reference |
| [36_reverse_level_order_print.cpp](36_reverse_level_order_print.cpp) | BFS Stack Print | Printing level order from bottom to top |
| [37_find_max_element_binary_tree.cpp](37_find_max_element_binary_tree.cpp) | Tree Extrema | Global maximum node search |
| [38_max_sum_level_binary_tree.cpp](38_max_sum_level_binary_tree.cpp) | Iterative Level Sum | Finding level with maximum accumulated sum |
| [39_max_sum_level_recursive.cpp](39_max_sum_level_recursive.cpp) | Recursive Level Sum | Depth-indexed vector accumulation |
| [40_search_element_binary_tree.cpp](40_search_element_binary_tree.cpp) | DFS Search | Linear search in unsorted binary tree |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 30_Find_LCA_Binary_tree.cpp -o lca && ./lca
```
