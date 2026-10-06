#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool areRotations(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
    }
};

int main() {
    Solution sol;
    string s1 = "ABCD", s2 = "CDAB";
    cout << s2 << " is rotation of " << s1 << ": " << (sol.areRotations(s1, s2) ? "Yes" : "No") << endl;
    return 0;
}
