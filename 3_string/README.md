# 3_String: String Processing & Pattern Matching

Complete C++20 implementations of the classic 35 string algorithms covering pattern matching (KMP, Rabin-Karp, Boyer-Moore), palindromes, anagrams, permutations, and DP string alignment.

## Problems & Solutions

| File | Pattern / Problem | Key Concept |
|------|-------------------|-------------|
| [0_Reverse_String.cpp](0_Reverse_String.cpp) | Two Pointer | In-place character vector reversal |
| [1_Palindrome_String.cpp](1_Palindrome_String.cpp) | Two Pointer | Symmetric character comparison |
| [2_Find_Duplicate_characters_in_a_string.cpp](2_Find_Duplicate_characters_in_a_string.cpp) | Frequency Hash Map | Counting character occurrences |
| [4_Strings_are_rotations_of_other.cpp](4_Strings_are_rotations_of_other.cpp) | String Concatenation | Substring check in $s_1 + s_1$ |
| [5_Checking_valid_shuffle_of_two_Strings.cpp](5_Checking_valid_shuffle_of_two_Strings.cpp) | Sorting & Comparison | Valid interleaved shuffle verification |
| [6_Count_and_Say_problem.cpp](6_Count_and_Say_problem.cpp) | Run-Length Encoding | Recursive look-and-say sequence generator |
| [7_Longest_Palindrome_String.cpp](7_Longest_Palindrome_String.cpp) | Expand Around Center | Longest palindromic substring in $O(n^2)$ |
| [8_Find_Longest_Recurring_Subsequence_String.cpp](8_Find_Longest_Recurring_Subsequence_String.cpp) | Dynamic Programming | Modified LCS where $i \neq j$ |
| [9_Print_all_Subsequences_string.cpp](9_Print_all_Subsequences_string.cpp) | Backtracking / Recursion | Pick and don't-pick enumeration |
| [10_All_permutations_string.cpp](10_All_permutations_string.cpp) | Backtracking | In-place swapping permutation generator |
| [11_Split_binary_string_0s_and_1s.cpp](11_Split_binary_string_0s_and_1s.cpp) | Greedy Scan | Splitting into maximum equal 0/1 substrings |
| [14_Next_Permutation.cpp](14_Next_Permutation.cpp) | Lexicographical Next | Pivot element swapping & suffix reversal |
| [15_Balanced_Parenthesis_problem_Imp.cpp](15_Balanced_Parenthesis_problem_Imp.cpp) | Stack | Bracket balance validation |
| [16_Word_break_Problem_Very_Imp.cpp](16_Word_break_Problem_Very_Imp.cpp) | Dynamic Programming | Segmenting string into dictionary words |
| [17_Rabin_Karp_Algo.cpp](17_Rabin_Karp_Algo.cpp) | Rolling Hash | Rolling polynomial hash pattern search |
| [18_KMP_Algo.cpp](18_KMP_Algo.cpp) | Knuth-Morris-Pratt | $O(n + m)$ search using LPS array |
| [19_Convert_sentence_into_its_equivalent_mobile_numeric_keypad_sequence.cpp](19_Convert_sentence_into_its_equivalent_mobile_numeric_keypad_sequence.cpp) | Lookup Table | Old mobile keypad numeric conversion |
| [20_Count_the_Reversals.cpp](20_Count_the_Reversals.cpp) | Greedy Stack | Minimum bracket reversals to balance |
| [21_Count_Palindromic_Subsequences.cpp](21_Count_Palindromic_Subsequences.cpp) | 2D Dynamic Programming | Inclusion-exclusion DP on intervals |
| [23_Search_Word_2D_Grid_characters.cpp](23_Search_Word_2D_Grid_characters.cpp) | 8-Directional Search | Word search in character matrix |
| [24_Boyer_Moore_Algorithm_Pattern_Searching.cpp](24_Boyer_Moore_Algorithm_Pattern_Searching.cpp) | Bad Character Heuristic | Right-to-left scanning with character skips |
| [25_Converting_Roman_Numerals_to_Decimal.cpp](25_Converting_Roman_Numerals_to_Decimal.cpp) | Lookahead Subtraction | Roman numeral value accumulation |
| [26_Longest_Common_Prefix.cpp](26_Longest_Common_Prefix.cpp) | Horizontal Scanning | Rolling common prefix reduction |
| [27_Number_flips_make_binary_string_alternate.cpp](27_Number_flips_make_binary_string_alternate.cpp) | Parity Check | Distance to alternating patterns "0101..." / "1010..." |
| [28_Find_the_first_repeated_word_in_string.cpp](28_Find_the_first_repeated_word_in_string.cpp) | String Stream & Hash Set | First recurring word lookup |
| [29_Minimum_swaps_bracket_balancing.cpp](29_Minimum_swaps_bracket_balancing.cpp) | Two Pointer Greedy | Unbalanced bracket position swapping |
| [30_Longest_Common_Subsequence.cpp](30_Longest_Common_Subsequence.cpp) | Classic 2D DP | Finding LCS length of two strings |
| [32_Smallest_distinct_window.cpp](32_Smallest_distinct_window.cpp) | Sliding Window | Minimum window containing all unique characters |
| [33_Rearrange_characters_string_no_two_adjacent_are_same.cpp](33_Rearrange_characters_string_no_two_adjacent_are_same.cpp) | Max-Heap Greedy | Alternating character placement by highest frequency |
| [34_Minimum_characters_added_front_make_string_palindrome.cpp](34_Minimum_characters_added_front_make_string_palindrome.cpp) | KMP LPS Array | Finding longest palindromic prefix |
| [35_Given_sequence_words_print_all_anagrams_together.cpp](35_Given_sequence_words_print_all_anagrams_together.cpp) | Sorted Key Hash Map | Grouping anagrams |
| [37_Remove_Consecutive_Characters.cpp](37_Remove_Consecutive_Characters.cpp) | Linear Filtering | Deduplicating adjacent identical characters |
| [41_Isomorphic_Strings.cpp](41_Isomorphic_Strings.cpp) | Dual Hash Mapping | Bijective character mapping validation |
| [42_Recursively_print_all_sentences_formed_from_list_word_lists.cpp](42_Recursively_print_all_sentences_formed_from_list_word_lists.cpp) | DFS / Backtracking | Cartesian product sentence generator |
| [string1.cpp](string1.cpp) | Brute Force Search | Baseline $O(n \cdot m)$ pattern finder |

## Compilation
```bash
g++ -std=c++20 -Wall -Wextra 18_KMP_Algo.cpp -o kmp && ./kmp
```
