#include <cassert>
#include <iostream>

class Solution {
public:
    int minimumDays(int S, int N, int M) {
        int totalFood = S * M;
        int buyingDays = S - (S / 7);

        if (buyingDays * N < totalFood) return -1;
        return (totalFood + N - 1) / N;
    }
};

int main() {
    Solution sol;
    assert(sol.minimumDays(10, 16, 2) == 2);
    assert(sol.minimumDays(10, 2, 2) == -1);
    assert(sol.minimumDays(1, 1, 1) == 1);
    assert(sol.minimumDays(2, 5, 2) == 1);

    std::cout << "12_Check_possible_survive_island tests passed.\n";
    return 0;
}
