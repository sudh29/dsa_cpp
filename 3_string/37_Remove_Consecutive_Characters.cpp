#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeConsecutiveCharacter(string S) {
        if (S.empty()) return "";
        string res = "";
        res += S[0];
        for (size_t i = 1; i < S.length(); i++) {
            if (S[i] != S[i - 1]) res += S[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aabaa";
    cout << "Removed consecutive characters from " << s << ": " << sol.removeConsecutiveCharacter(s) << endl;
    return 0;
}
