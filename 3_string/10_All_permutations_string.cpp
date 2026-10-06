#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void permute(string &s, int l, int r, vector<string> &res) {
        if (l == r) {
            res.push_back(s);
            return;
        }
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            permute(s, l + 1, r, res);
            swap(s[l], s[i]);
        }
    }

    vector<string> find_permutation(string S) {
        vector<string> res;
        permute(S, 0, S.length() - 1, res);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    auto perms = sol.find_permutation("ABC");
    cout << "Permutations of 'ABC': ";
    for (const string &p : perms) cout << p << " ";
    cout << endl;
    return 0;
}
