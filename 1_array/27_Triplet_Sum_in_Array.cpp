#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool find3Numbers(int A[], int n, int X) {
        sort(A, A + n);
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = A[i] + A[l] + A[r];
                if (sum == X) return true;
                if (sum < X) l++;
                else r--;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int A[] = {1, 4, 45, 6, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 13;
    cout << "Triplet sum equal to " << x << ": " << (sol.find3Numbers(A, n, x) ? "Found" : "Not Found") << endl;
    return 0;
}
