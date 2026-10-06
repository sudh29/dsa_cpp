#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include <string_view>

class Solution {
public:
    std::string printSequence(std::string_view S) {
        constexpr std::string_view keypad[] = {
            "2", "22", "222",
            "3", "33", "333",
            "4", "44", "444",
            "5", "55", "555",
            "6", "66", "666",
            "7", "77", "777", "7777",
            "8", "88", "888",
            "9", "99", "999", "9999"
        };
        std::string output;
        for (char c : S) {
            if (c == ' ') {
                output += "0";
            } else if (std::isupper(static_cast<unsigned char>(c))) {
                output += keypad[c - 'A'];
            }
        }
        return output;
    }
};

int main() {
    Solution sol;
    assert(sol.printSequence("HELLO WORLD") == "4433555555666096667775553");
    assert(sol.printSequence("A") == "2");
    assert(sol.printSequence("B") == "22");
    assert(sol.printSequence(" ") == "0");
    assert(sol.printSequence("GEEKSFORGEEKS") == "4333355777733366677743333557777");

    std::cout << "19_Convert_sentence_into_its_equivalent_mobile_numeric_keypad_sequence tests passed.\n";
    return 0;
}
