#include <iostream>
#include <string>

int count_pattern_occurrences(const std::string &text, const std::string &pattern) {
    if (pattern.empty()) return 0;
    int count = 0;
    size_t pos = text.find(pattern, 0);
    while (pos != std::string::npos) {
        count++;
        pos = text.find(pattern, pos + 1);
    }
    return count;
}

int main() {
    std::cout << "=== Pattern Count / Substring Search ===" << std::endl;
    std::string text = "abracadabra abracadabra";
    std::string pat = "abra";
    int occurrences = count_pattern_occurrences(text, pat);
    std::cout << "Pattern '" << pat << "' occurs " << occurrences << " times in '" << text << "'" << std::endl;
    return 0;
}
