#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToDecimal(string &str) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = 0, n = str.length();
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && val[str[i]] < val[str[i + 1]]) {
                res -= val[str[i]];
            } else {
                res += val[str[i]];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string roman = "MCMXCIV";
    cout << roman << " in decimal: " << sol.romanToDecimal(roman) << endl;
    return 0;
}
