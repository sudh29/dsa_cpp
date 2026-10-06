#include <iostream>
#include <vector>
#include <algorithm>

int longestSubsequence(int n, const std::vector<int>& a) {
    (void)n;
    std::vector<int> tails;
    for (int x : a) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    return tails.size();
}

int main() {
    std::vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    std::cout << "LIS length: " << longestSubsequence(a.size(), a) << " (expected 6)\n";
    return 0;
}
