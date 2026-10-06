# 13_Trie: Prefix Trees & Retrieval

Complete C++20 implementations of Trie data structures, prefix queries, dictionary word break, phone directory auto-completion, and binary matrix deduplication.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Construct_trie_from_scratch.cpp](0_Construct_trie_from_scratch.cpp) | Trie ADT | Fixed 26-ary tree (`insert`, `search`) |
| [1_Shortest_Unique_prefix_for_every_word.cpp](1_Shortest_Unique_prefix_for_every_word.cpp) | Node Frequency | Finding earliest node with prefix frequency 1 |
| [2_Word_Break_Problem_Trie_solution.cpp](2_Word_Break_Problem_Trie_solution.cpp) | Trie + Memoization | Prefix matching for sentence segmentation |
| [3_Print_Anagrams_Together.cpp](3_Print_Anagrams_Together.cpp) | Grouping | Sorting anagram keys and grouping entries |
| [4_Phone_directory.cpp](4_Phone_directory.cpp) | Auto-Complete | Prefix query returning sorted contact set |
| [5_Unique_rows_boolean_matrix.cpp](5_Unique_rows_boolean_matrix.cpp) | Binary Trie | 2-ary Trie deduplicating matrix bit vectors |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 0_Construct_trie_from_scratch.cpp -o trie && ./trie
```
