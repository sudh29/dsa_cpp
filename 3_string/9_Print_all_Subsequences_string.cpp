#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateSubsequences(const string &str, int idx, string current, vector<string> &res) {
    if (idx == (int)str.length()) {
        if (!current.empty()) res.push_back(current);
        return;
    }
    // Include
    generateSubsequences(str, idx + 1, current + str[idx], res);
    // Exclude
    generateSubsequences(str, idx + 1, current, res);
}

int main() {
    string s = "abc";
    vector<string> res;
    generateSubsequences(s, 0, "", res);
    cout << "Subsequences of '" << s << "': ";
    for (const string &sub : res) cout << sub << " ";
    cout << endl;
    return 0;
}
