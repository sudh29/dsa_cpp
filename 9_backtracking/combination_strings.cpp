#include <iostream>
#include <vector>
#include <string>

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
    std::cout << "First Test:\n";
    std::vector<std::string> set1 = {"1", "2", "3"};
    std::vector<std::string> res1;
    allCombinationStr(set1, "", 2, res1);
    for (const auto& s : res1) std::cout << s << " ";
    std::cout << "\n\nSecond Test:\n";

    std::vector<std::string> set2 = {"a", "b", "c"};
    std::vector<std::string> res2;
    allCombinationStr(set2, "", 2, res2);
    for (const auto& s : res2) std::cout << s << " ";
    std::cout << "\n";
    return 0;
}
