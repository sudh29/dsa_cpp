#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWord(string str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            swap(str[left++], str[right--]);
        }
        return str;
    }
};

int main() {
    Solution sol;
    string s = "Geeks";
    cout << "Original: " << s << " | Reversed: " << sol.reverseWord(s) << endl;
    return 0;
}
