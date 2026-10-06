#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumNumberOfSwaps(string S) {
        vector<int> pos;
        for (int i = 0; i < (int)S.length(); i++) {
            if (S[i] == '[') pos.push_back(i);
        }

        int count = 0, p = 0, swaps = 0;
        for (int i = 0; i < (int)S.length(); i++) {
            if (S[i] == '[') {
                count++;
                p++;
            } else {
                count--;
            }

            if (count < 0) {
                swaps += (pos[p] - i);
                swap(S[i], S[pos[p]]);
                p++;
                count = 1;
            }
        }
        return swaps;
    }
};

int main() {
    Solution sol;
    string s = "[]][][";
    cout << "Min swaps for bracket balancing: " << sol.minimumNumberOfSwaps(s) << endl;
    return 0;
}
