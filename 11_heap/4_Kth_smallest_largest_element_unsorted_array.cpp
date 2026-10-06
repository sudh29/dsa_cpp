#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> maxH;
        for (int i = l; i <= r; i++) {
            maxH.push(arr[i]);
            if (maxH.size() > (size_t)k) maxH.pop();
        }
        return maxH.top();
    }
};

int main() {
    Solution sol;
    int arr[] = {7, 10, 4, 3, 20, 15};
    cout << "3rd smallest element: " << sol.kthSmallest(arr, 0, 5, 3) << endl;
    return 0;
}
