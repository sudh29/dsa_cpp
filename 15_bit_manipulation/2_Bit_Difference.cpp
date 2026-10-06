#include <iostream>

using namespace std;

class Solution {
public:
    int countBitsFlip(int a, int b) {
        int xor_val = a ^ b;
        return __builtin_popcount(xor_val);
    }
};

int main() {
    Solution sol;
    int a = 10, b = 20;
    cout << "Bits to flip from " << a << " to " << b << ": " << sol.countBitsFlip(a, b) << endl;
    return 0;
}
