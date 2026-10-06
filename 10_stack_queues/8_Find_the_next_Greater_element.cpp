#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        vector<long long> res(n, -1);
        stack<long long> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                res[i] = s.top();
            }
            s.push(arr[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<long long> arr = {1, 3, 2, 4};
    auto res = sol.nextLargerElement(arr, arr.size());
    cout << "Next greater elements: ";
    for (auto v : res) cout << v << " ";
    cout << endl;
    return 0;
}
