#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void rearrange(int arr[], int n) {
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }

        int i = 0;
        size_t p = 0, q = 0;
        while (p < pos.size() && q < neg.size()) {
            arr[i++] = pos[p++];
            arr[i++] = neg[q++];
        }
        while (p < pos.size()) arr[i++] = pos[p++];
        while (q < neg.size()) arr[i++] = neg[q++];
    }
};

int main() {
    Solution sol;
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.rearrange(arr, n);
    cout << "Alternating pos/neg: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    assert(arr[0] == 9 && arr[1] == -2 && arr[2] == 4 && arr[3] == -1);
    return 0;
}
