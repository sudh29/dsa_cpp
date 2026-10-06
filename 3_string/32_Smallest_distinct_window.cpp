#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    int findSubString(string str) {
        unordered_set<char> distinct(str.begin(), str.end());
        int total_distinct = distinct.size();

        vector<int> count(256, 0);
        int start = 0, min_len = INT_MAX, distinct_seen = 0;

        for (int end = 0; end < (int)str.length(); end++) {
            if (count[(unsigned char)str[end]] == 0) distinct_seen++;
            count[(unsigned char)str[end]]++;

            while (distinct_seen == total_distinct) {
                min_len = min(min_len, end - start + 1);
                count[(unsigned char)str[start]]--;
                if (count[(unsigned char)str[start]] == 0) distinct_seen--;
                start++;
            }
        }
        return min_len;
    }
};

int main() {
    Solution sol;
    string s = "aabcbcdbca";
    cout << "Smallest distinct window length: " << sol.findSubString(s) << endl;
    return 0;
}
