#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void maxHeapify(vector<int> &arr, int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> merged = a;
        merged.insert(merged.end(), b.begin(), b.end());
        int total = n + m;
        for (int i = total / 2 - 1; i >= 0; i--) {
            maxHeapify(merged, total, i);
        }
        return merged;
    }
};

int main() {
    Solution sol;
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    auto merged = sol.mergeHeaps(a, b, 4, 3);
    cout << "Merged Max Heap root: " << merged[0] << endl;
    return 0;
}
