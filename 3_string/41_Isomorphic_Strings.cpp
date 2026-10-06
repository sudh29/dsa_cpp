#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool areIsomorphic(string str1, string str2) {
        if (str1.length() != str2.length()) return false;
        vector<int> m1(256, -1), m2(256, -1);

        for (size_t i = 0; i < str1.length(); i++) {
            unsigned char c1 = str1[i], c2 = str2[i];
            if (m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;
                m2[c2] = c1;
            } else if (m1[c1] != c2 || m2[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << "aab & xxy isomorphic: " << (sol.areIsomorphic("aab", "xxy") ? "Yes" : "No") << endl;
    cout << "aab & xyz isomorphic: " << (sol.areIsomorphic("aab", "xyz") ? "Yes" : "No") << endl;
    return 0;
}
