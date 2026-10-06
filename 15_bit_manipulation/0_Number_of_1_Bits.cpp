#include <iostream>

using namespace std;

class Solution {
public:
    int setBits(int N) {
        int count = 0;
        while (N > 0) {
            N &= (N - 1);
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    int n = 6;
    cout << "Set bits in " << n << ": " << sol.setBits(n) << endl;
    return 0;
}
