#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

bool validShuffle(std::string_view str1, std::string_view str2, std::string_view shuffle) {
    if (str1.length() + str2.length() != shuffle.length()) return false;
    std::string sortedShuffle(shuffle);
    std::sort(sortedShuffle.begin(), sortedShuffle.end());

    std::string combined = std::string(str1) + std::string(str2);
    std::sort(combined.begin(), combined.end());
    return combined == sortedShuffle;
}

int main() {
    assert(validShuffle("XY", "12", "1X2Y"));
    assert(validShuffle("ABC", "123", "A1B2C3"));
    assert(!validShuffle("XY", "12", "1X2Z"));
    assert(!validShuffle("XY", "12", "1X2"));

    std::cout << "3_string 5_Checking_valid_shuffle_of_two_Strings: All tests passed.\n";
    return 0;
}
