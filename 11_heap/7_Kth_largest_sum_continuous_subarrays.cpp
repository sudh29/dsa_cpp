#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthLargest(int N, int K, vector<int> &Arr) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += Arr[j];
                minH.push(sum);
                if (minH.size() > (size_t)K) minH.pop();
            }
        }
        return minH.top();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 6, 4, 1};
    cout << "3rd largest continuous subarray sum: " << sol.kthLargest(4, 3, arr) << endl;
    return 0;
}
