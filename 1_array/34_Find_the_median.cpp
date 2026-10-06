#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int find_median(vector<int> v) {
        sort(v.begin(), v.end());
        int n = v.size();
        if (n % 2 != 0) return v[n / 2];
        return (v[n / 2 - 1] + v[n / 2]) / 2;
    }
};

int main() {
    Solution sol;
    vector<int> v = {90, 100, 78, 89, 67};
    cout << "Median of array: " << sol.find_median(v) << endl;
    return 0;
}
