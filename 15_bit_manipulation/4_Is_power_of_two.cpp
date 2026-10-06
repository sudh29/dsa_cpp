#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerofTwo(long long n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    long long n1 = 16, n2 = 18;
    cout << n1 << " is power of 2: " << (sol.isPowerofTwo(n1) ? "Yes" : "No") << endl;
    cout << n2 << " is power of 2: " << (sol.isPowerofTwo(n2) ? "Yes" : "No") << endl;
    return 0;
}
