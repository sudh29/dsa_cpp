#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void allCombinationStr(const std::vector<std::string>& arr, const std::string& prefix, int k,
                       std::vector<std::string>& res) {
    if (k == 0) {
        res.push_back(prefix);
        return;
    }
    for (size_t i = 0; i < arr.size(); ++i) {
        allCombinationStr(arr, prefix + arr[i], k - 1, res);
    }
}

int main() {
    std::vector<std::string> set1 = {"1", "2", "3"};
    std::vector<std::string> res1;
    allCombinationStr(set1, "", 2, res1);
    assert(res1.size() == 9);
    assert(res1[0] == "11");
    assert(res1[8] == "33");

    std::vector<std::string> set2 = {"a", "b", "c"};
    std::vector<std::string> res2;
    allCombinationStr(set2, "", 2, res2);
    assert(res2.size() == 9);
    assert(res2[0] == "aa");

    std::cout << "combination_strings tests passed.\n";
    return 0;
}
