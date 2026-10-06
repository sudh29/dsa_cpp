#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (const auto &[ch, count] : freq) pq.push({count, ch});

        string res = "";
        pair<int, char> prev = {-1, '#'};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            res += cur.second;

            if (prev.first > 0) pq.push(prev);

            cur.first--;
            prev = cur;
        }

        return (res.length() == s.length()) ? res : "";
    }
};

int main() {
    Solution sol;
    cout << "Reorganized 'aab': " << sol.reorganizeString("aab") << endl;
    cout << "Reorganized 'aaab': '" << sol.reorganizeString("aaab") << "'" << endl;
    return 0;
}
