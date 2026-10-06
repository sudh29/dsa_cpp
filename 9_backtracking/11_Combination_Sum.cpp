#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

void solve(const std::vector<int>& arr, int target, std::vector<int>& current,
           size_t idx, std::vector<std::vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (size_t i = idx; i < arr.size(); ++i) {
        if (arr[i] > target) break;
        if (i > idx && arr[i] == arr[i - 1]) continue;

        current.push_back(arr[i]);
        solve(arr, target - arr[i], current, i, result);
        current.pop_back();
    }
}

std::vector<std::vector<int>> combinationalSum(std::vector<int>& A, int B) {
    std::sort(A.begin(), A.end());
    // remove duplicates for classic combination sum where elements can be reused
    A.erase(std::unique(A.begin(), A.end()), A.end());

    std::vector<std::vector<int>> result;
    std::vector<int> current;
    solve(A, B, current, 0, result);
    return result;
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8};
    int target = 8;
    auto combs = combinationalSum(arr, target);
    assert(!combs.empty());
    for (const auto& comb : combs) {
        int sum = 0;
        for (int x : comb) sum += x;
        assert(sum == target);
    }
    std::vector<int> first = {2, 2, 2, 2};
    assert(combs[0] == first);

    std::vector<int> arr2 = {10};
    assert(combinationalSum(arr2, 5).empty());

    std::cout << "11_Combination_Sum tests passed.\n";
    return 0;
}
