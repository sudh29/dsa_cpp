#include <cassert>
#include <iostream>

class Solution {
public:
    int inSequence(int A, int B, int C) {
        if (C == 0) return A == B ? 1 : 0;
        int d = (B - A) / C;
        int r = (B - A) % C;
        return (d >= 0 && r == 0) ? 1 : 0;
    }
};

int main() {
    Solution sol;
    assert(sol.inSequence(1, 7, 2) == 1);
    assert(sol.inSequence(1, 8, 2) == 0);
    assert(sol.inSequence(1, 1, 0) == 1);
    assert(sol.inSequence(1, 2, 0) == 0);
    assert(sol.inSequence(10, 4, -2) == 1);
    assert(sol.inSequence(10, 5, -2) == 0);

    std::cout << "27_Arithmetic_Number tests passed.\n";
    return 0;
}
