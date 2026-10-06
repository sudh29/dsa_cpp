#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

    int current_end = INT_MIN;
    int max_chain = 0;

    for (const auto& pair : pairs) {
        if (current_end == INT_MIN || pair[0] > current_end) {
            current_end = pair[1];
            max_chain++;
        }
    }
    return max_chain;
}

int main() {
    std::vector<std::vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    std::cout << "Longest pair chain: " << findLongestChain(pairs) << " (expected 2)\n";
    return 0;
}
