#include <cassert>
#include <iostream>
#include <string_view>
#include <unordered_map>

class Solution {
public:
    int romanToDecimal(std::string_view str) {
        auto val = [](char c) -> int {
            switch (c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };
        int res = 0;
        int n = static_cast<int>(str.length());
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val(str[i]) < val(str[i + 1])) {
                res -= val(str[i]);
            } else {
                res += val(str[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    assert(sol.romanToDecimal("MCMXCIV") == 1994);
    assert(sol.romanToDecimal("III") == 3);
    assert(sol.romanToDecimal("IV") == 4);
    assert(sol.romanToDecimal("IX") == 9);
    assert(sol.romanToDecimal("LVIII") == 58);
    assert(sol.romanToDecimal("") == 0);

    std::cout << "25_Converting_Roman_Numerals_to_Decimal tests passed.\n";
    return 0;
}
