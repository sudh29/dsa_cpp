#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n <= 0) return "";
        std::string res = "1";
        for (int i = 1; i < n; ++i) {
            std::string nextRes;
            int count = 1;
            for (size_t j = 1; j < res.length(); ++j) {
                if (res[j] == res[j - 1]) {
                    count++;
                } else {
                    nextRes += std::to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            nextRes += std::to_string(count) + res.back();
            res = nextRes;
        }
        return res;
    }
};

int main() {
    Solution sol;
    assert(sol.countAndSay(1) == "1");
    assert(sol.countAndSay(2) == "11");
    assert(sol.countAndSay(3) == "21");
    assert(sol.countAndSay(4) == "1211");
    assert(sol.countAndSay(5) == "111221");

    std::cout << "3_string 6_Count_and_Say_problem: All tests passed.\n";
    return 0;
}
