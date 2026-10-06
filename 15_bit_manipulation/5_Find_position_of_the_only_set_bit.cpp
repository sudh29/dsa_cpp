#include <iostream>

using namespace std;

class Solution {
public:
    int findPosition(int N) {
        if (N <= 0 || (N & (N - 1)) != 0) return -1;
        int pos = 1;
        while ((1 << (pos - 1)) != N) pos++;
        return pos;
    }
};

int main() {
    Solution sol;
    cout << "Position of only set bit in 16: " << sol.findPosition(16) << endl;
    cout << "Position of only set bit in 12: " << sol.findPosition(12) << endl;
    return 0;
}
