#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countTriplets(long long arr[], int n, long long sum) {
        sort(arr, arr + n);
        long long count = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] < sum) {
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    long long arr[] = {-2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long sum = 2;
    cout << "Triplets with sum < " << sum << ": " << sol.countTriplets(arr, n, sum) << endl;
    return 0;
}
