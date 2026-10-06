#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nextPermutation(int N, vector<int> arr) {
        int i = N - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i >= 0) {
            int j = N - 1;
            while (arr[j] <= arr[i]) j--;
            swap(arr[i], arr[j]);
        }
        reverse(arr.begin() + i + 1, arr.end());
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 6, 5, 4};
    auto nextp = sol.nextPermutation(arr.size(), arr);
    cout << "Next permutation: ";
    for (int v : nextp) cout << v << " ";
    cout << endl;
    return 0;
}
