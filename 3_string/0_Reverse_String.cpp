#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = (int)s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    cout << "Reversed: ";
    for (char c : s) cout << c;
    cout << endl;
    return 0;
}
