#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxSubStr(string str) {
        int count0 = 0, count1 = 0, splits = 0;
        for (char c : str) {
            if (c == '0') count0++;
            else count1++;
            if (count0 == count1) splits++;
        }
        if (count0 != count1) return -1;
        return splits;
    }
};

int main() {
    Solution sol;
    string s = "0100110101";
    cout << "Max 0/1 substrings for " << s << ": " << sol.maxSubStr(s) << endl;
    return 0;
}
