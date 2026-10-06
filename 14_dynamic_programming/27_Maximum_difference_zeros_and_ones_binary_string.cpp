#include <iostream>
#include <string>
#include <algorithm>

int maxSubstring(const std::string& S) {
    int max_diff = -1;
    int curr = 0;

    for (char c : S) {
        int val = (c == '0') ? 1 : -1;
        curr += val;
        max_diff = std::max(max_diff, curr);
        if (curr < 0) curr = 0;
    }
    return max_diff > 0 ? max_diff : -1;
}

int main() {
    std::string s = "11000010001";
    std::cout << "Max difference zeros and ones: " << maxSubstring(s) << " (expected 6)\n";
    return 0;
}
