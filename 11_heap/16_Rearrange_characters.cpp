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
        for (auto &[c, cnt] : freq) pq.push({cnt, c});

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
        return (res.length() == str.length()) ? res : "-1";
    }
};

int main() {
    Solution sol;
    cout << "Rearrange 'geeksforgeeks': " << sol.rearrangeString("geeksforgeeks") << endl;
    return 0;
}
