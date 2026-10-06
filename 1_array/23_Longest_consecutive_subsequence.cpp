#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
        unordered_set<int> S(arr, arr + N);
        int ans = 0;

        for (int i = 0; i < N; i++) {
            if (S.find(arr[i] - 1) == S.end()) {
                int j = arr[i];
                while (S.find(j) != S.end()) j++;
                ans = max(ans, j - arr[i]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Longest consecutive subsequence length: " << sol.findLongestConseqSubseq(arr, n) << endl;
    return 0;
}
