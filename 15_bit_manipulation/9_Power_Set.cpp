#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        int total = 1 << n;
        vector<string> res;

        for (int i = 1; i < total; i++) {
            string sub = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sub += s[j];
                }
            }
            res.push_back(sub);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    auto pset = sol.AllPossibleStrings(s);
    cout << "Power set of '" << s << "': ";
    for (const string &str : pset) cout << str << " ";
    cout << endl;
    return 0;
}
