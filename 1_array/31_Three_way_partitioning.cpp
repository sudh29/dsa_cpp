#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b) {
        int low = 0, mid = 0, high = (int)array.size() - 1;
        while (mid <= high) {
            if (array[mid] < a) {
                swap(array[low++], array[mid++]);
            } else if (array[mid] > b) {
                swap(array[mid], array[high--]);
            } else {
                mid++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    sol.threeWayPartition(arr, 10, 20);
    cout << "Three-way partitioned around [10, 20]: ";
    for (int v : arr) cout << v << " ";
    cout << endl;
    return 0;
}
