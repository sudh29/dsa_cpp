#include <iostream>

using namespace std;

class Solution {
public:
    int inSequence(int A, int B, int C) {
        if (C == 0) return A == B;
        int d = (B - A) / C;
        int r = (B - A) % C;
        return (d >= 0 && r == 0) ? 1 : 0;
    }
};

int main() {
    Solution sol;
    cout << "Is 7 in seq (1, step 2): " << sol.inSequence(1, 7, 2) << endl;
    cout << "Is 8 in seq (1, step 2): " << sol.inSequence(1, 8, 2) << endl;
    return 0;
}
