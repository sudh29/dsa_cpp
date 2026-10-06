#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int isPalindrome(string S) {
        int l = 0, r = S.length() - 1;
        while (l < r) {
            if (S[l++] != S[r--]) return 0;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    string s = "racecar";
    cout << s << " is palindrome: " << (sol.isPalindrome(s) ? "Yes" : "No") << endl;
    return 0;
}
