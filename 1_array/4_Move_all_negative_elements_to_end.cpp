#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void segregateElements(int arr[], int n) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) temp.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) temp.push_back(arr[i]);
        }
        for (int i = 0; i < n; i++) arr[i] = temp[i];
    }
};

int main() {
    Solution sol;
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol.segregateElements(arr, n);
    cout << "Segregated array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
