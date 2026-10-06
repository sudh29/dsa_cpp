#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        int i = 0, j = 0, k = 0;
        vector<int> res;

        while (i < n1 && j < n2 && k < n3) {
            if (A[i] == B[j] && B[j] == C[k]) {
                if (res.empty() || res.back() != A[i]) {
                    res.push_back(A[i]);
                }
                i++; j++; k++;
            } else if (A[i] < B[j]) {
                i++;
            } else if (B[j] < C[k]) {
                j++;
            } else {
                k++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    auto common = sol.commonElements(A, B, C, 6, 5, 8);
    cout << "Common in 3 sorted arrays: ";
    for (int v : common) cout << v << " ";
    cout << endl;
    return 0;
}
