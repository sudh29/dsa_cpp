#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string chooseandswap(string a) {
        set<char> s(a.begin(), a.end());
        for (size_t i = 0; i < a.length(); i++) {
            s.erase(a[i]);
            if (s.empty()) break;
            char ch = *s.begin();
            if (ch < a[i]) {
                char ch2 = a[i];
                for (size_t j = 0; j < a.length(); j++) {
                    if (a[j] == ch) a[j] = ch2;
                    else if (a[j] == ch2) a[j] = ch;
                }
                break;
            }
        }
        return a;
    }
};

int main() {
    Solution sol;
    cout << "Choose and swap 'ccad': " << sol.chooseandswap("ccad") << endl;
    return 0;
}
