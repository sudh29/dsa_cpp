#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

void inorder(std::span<const int> a, size_t index, std::vector<int> &ans) {
    if (index >= a.size()) return;
    inorder(a, 2 * index + 1, ans);
    ans.push_back(a[index]);
    inorder(a, 2 * index + 2, ans);
}

int minSwaps(std::span<const int> a) {
    size_t n = a.size();
    if (n <= 1) return 0;

    std::vector<int> ans;
    ans.reserve(n);
    inorder(a, 0, ans);

    std::vector<std::pair<int, size_t>> v(n);
    for (size_t i = 0; i < n; ++i) {
        v[i] = {ans[i], i};
    }
    std::sort(v.begin(), v.end());

    std::vector<bool> visited(n, false);
    int swaps = 0;

    for (size_t i = 0; i < n; ++i) {
        if (visited[i] || v[i].second == i) continue;
        int cycleSize = 0;
        size_t j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            cycleSize++;
        }
        if (cycleSize > 1) {
            swaps += (cycleSize - 1);
        }
    }
    return swaps;
}

int main() {
    std::vector<int> a = {5, 6, 7, 8, 9, 10, 11};
    // Inorder: 8, 6, 9, 5, 10, 7, 11
    // Sorted inorder: 5, 6, 7, 8, 9, 10, 11
    // Min swaps required: 3
    assert(minSwaps(a) == 3);

    std::vector<int> alreadyBST = {4, 2, 6, 1, 3, 5, 7};
    // Inorder: 1, 2, 3, 4, 5, 6, 7 (already sorted)
    assert(minSwaps(alreadyBST) == 0);

    std::cout << "6_binary_tree 20_Find_minimum_swaps_required_convert_Binary_tree_into_BST: All tests passed.\n";
    return 0;
}
