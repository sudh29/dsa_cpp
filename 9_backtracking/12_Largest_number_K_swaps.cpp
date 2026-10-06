#include <iostream>
#include <string>
#include <algorithm>

void solve(std::string& str, int k, std::string& max_str, size_t idx) {
    if (k == 0 || idx == str.length()) return;

    char max_char = str[idx];
    for (size_t i = idx + 1; i < str.length(); ++i) {
        if (str[i] > max_char) {
            max_char = str[i];
        }
    }

    if (max_char != str[idx]) {
        --k;
    }

    for (int j = str.length() - 1; j >= static_cast<int>(idx); --j) {
        if (str[j] == max_char) {
            std::swap(str[idx], str[j]);
            if (str > max_str) {
                max_str = str;
            }
            solve(str, k, max_str, idx + 1);
            std::swap(str[idx], str[j]); // backtrack
        }
    }
}

std::string findMaximumNum(std::string str, int k) {
    std::string max_str = str;
    solve(str, k, max_str, 0);
    return max_str;
}

int main() {
    std::string s1 = "1234567";
    int k1 = 4;
    std::cout << "Max num after " << k1 << " swaps: " << findMaximumNum(s1, k1) << " (expected 7654321)\n";

    std::string s2 = "3435335";
    int k2 = 3;
    std::cout << "Max num after " << k2 << " swaps: " << findMaximumNum(s2, k2) << " (expected 5543333)\n";
    return 0;
}
