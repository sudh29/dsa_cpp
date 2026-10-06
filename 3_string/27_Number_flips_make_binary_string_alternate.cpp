#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlips(string S) {
        int flips0 = 0, flips1 = 0;
        for (size_t i = 0; i < S.length(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            if (S[i] != expected0) flips0++;
            if (S[i] != expected1) flips1++;
        }
        return min(flips0, flips1);
    }
};

int main() {
    Solution sol;
    string s = "0001010111";
    cout << "Min flips to alternate: " << sol.minFlips(s) << endl;
    return 0;
}
