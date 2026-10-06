#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

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
    assert(findMaximumNum("1234567", 4) == "7654321");
    assert(findMaximumNum("3435335", 3) == "5543333");
    assert(findMaximumNum("123", 0) == "123");
    assert(findMaximumNum("", 2) == "");

    std::cout << "12_Largest_number_K_swaps tests passed.\n";
    return 0;
}
