#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string printSequence(string S) {
        string keypad[] = {
            "2", "22", "222",
            "3", "33", "333",
            "4", "44", "444",
            "5", "55", "555",
            "6", "66", "666",
            "7", "77", "777", "7777",
            "8", "88", "888",
            "9", "99", "999", "9999"
        };
        string output = "";
        for (char c : S) {
            if (c == ' ') output += "0";
            else if (isupper(c)) output += keypad[c - 'A'];
        }
        return output;
    }
};

int main() {
    Solution sol;
    cout << "Keypad sequence for 'HELLO WORLD': " << sol.printSequence("HELLO WORLD") << endl;
    return 0;
}
