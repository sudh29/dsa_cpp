#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        for (int i = 1; i < n; i++) {
            string next_res = "";
            int count = 1;
            for (size_t j = 1; j < res.length(); j++) {
                if (res[j] == res[j - 1]) {
                    count++;
                } else {
                    next_res += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            next_res += to_string(count) + res.back();
            res = next_res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << "Count and Say (4): " << sol.countAndSay(4) << endl;
    return 0;
}
