#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        vector<int> freq(26, 0);
        queue<char> q;
        string ans = "";

        for (char c : A) {
            freq[c - 'a']++;
            q.push(c);

            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }

            if (q.empty()) ans += '#';
            else ans += q.front();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string stream = "aabc";
    cout << "Stream: " << stream << " -> " << sol.FirstNonRepeating(stream) << endl;
    return 0;
}
