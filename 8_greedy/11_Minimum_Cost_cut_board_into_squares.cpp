#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

class Solution {
public:
    int minimumCostOfBreaking(std::vector<int> X, std::vector<int> Y, int M, int N) {
        std::sort(X.rbegin(), X.rend());
        std::sort(Y.rbegin(), Y.rend());

        int hzPieces = 1, vtPieces = 1;
        int i = 0, j = 0, totalCost = 0;

        while (i < M - 1 && j < N - 1) {
            if (X[i] >= Y[j]) {
                totalCost += X[i] * vtPieces;
                hzPieces++;
                i++;
            } else {
                totalCost += Y[j] * hzPieces;
                vtPieces++;
                j++;
            }
        }

        while (i < M - 1) {
            totalCost += X[i++] * vtPieces;
        }
        while (j < N - 1) {
            totalCost += Y[j++] * hzPieces;
        }
        return totalCost;
    }
};

int main() {
    Solution sol;
    std::vector<int> X = {2, 1, 3, 1, 4};
    std::vector<int> Y = {4, 1, 2};
    assert(sol.minimumCostOfBreaking(X, Y, 6, 4) == 42);

    assert(sol.minimumCostOfBreaking({}, {}, 1, 1) == 0);

    std::cout << "11_Minimum_Cost_cut_board_into_squares tests passed.\n";
    return 0;
}
