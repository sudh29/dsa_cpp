#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool are_anagrams(std::string s1, std::string s2) {
    if (s1.length() != s2.length()) return false;
    std::vector<int> count(256, 0);
    for (char c : s1) count[(unsigned char)c]++;
    for (char c : s2) {
        if (--count[(unsigned char)c] < 0) return false;
    }
    return true;
}

int main() {
    std::cout << "=== Anagram Checker in C++ ===" << std::endl;
    std::string s1 = "listen", s2 = "silent";
    std::string s3 = "hello", s4 = "world";

    std::cout << s1 << " & " << s2 << ": " << (are_anagrams(s1, s2) ? "ANAGRAM" : "NOT anagram") << std::endl;
    std::cout << s3 << " & " << s4 << ": " << (are_anagrams(s3, s4) ? "ANAGRAM" : "NOT anagram") << std::endl;
    return 0;
}
