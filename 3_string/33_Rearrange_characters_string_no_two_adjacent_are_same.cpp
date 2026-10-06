#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string rearrangeString(string str) {
        unordered_map<char, int> freq;
        for (char c : str) freq[c]++;

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

        if (res.length() != str.length()) return "";
        return res;
    }
};

int main() {
    Solution sol;
    string s = "aaabc";
    cout << "Rearranged '" << s << "': " << sol.rearrangeString(s) << endl;
    return 0;
}
