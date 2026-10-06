#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
        sort(X.rbegin(), X.rend());
        sort(Y.rbegin(), Y.rend());

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
    vector<int> X = {2, 1, 3, 1, 4};
    vector<int> Y = {4, 1, 2};
    cout << "Minimum cost of cutting board: " << sol.minimumCostOfBreaking(X, Y, 6, 4) << endl;
    return 0;
}
