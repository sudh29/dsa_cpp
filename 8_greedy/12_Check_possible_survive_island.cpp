#include <iostream>

using namespace std;

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
    cout << "Min days to survive (S=10, N=16, M=2): " << sol.minimumDays(10, 16, 2) << endl;
    return 0;
}
