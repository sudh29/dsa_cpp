#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> factorial(int N) {
        vector<int> res;
        res.push_back(1);

        for (int x = 2; x <= N; x++) {
            int carry = 0;
            for (size_t i = 0; i < res.size(); i++) {
                int prod = res[i] * x + carry;
                res[i] = prod % 10;
                carry = prod / 10;
            }
            while (carry) {
                res.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    int n = 10;
    auto digits = sol.factorial(n);
    cout << n << "! = ";
    for (int d : digits) cout << d;
    cout << endl;
    return 0;
}
