#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <utility>
#include <vector>

std::pair<int, int> bishuQuery(std::span<const int> soldiers, std::span<const int> prefix, int power) {
    auto it = std::upper_bound(soldiers.begin(), soldiers.end(), power);
    int idx = static_cast<int>(std::distance(soldiers.begin(), it));
    return {idx, prefix[idx]};
}

int main() {
    int n = 7;
    std::vector<int> soldiers = {1, 2, 3, 4, 5, 6, 7};
    std::sort(soldiers.begin(), soldiers.end());

    std::vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + soldiers[i];

    auto r1 = bishuQuery(soldiers, prefix, 3);
    assert(r1.first == 3 && r1.second == 6);

    auto r2 = bishuQuery(soldiers, prefix, 10);
    assert(r2.first == 7 && r2.second == 28);

    auto r3 = bishuQuery(soldiers, prefix, 2);
    assert(r3.first == 2 && r3.second == 3);

    auto r4 = bishuQuery(soldiers, prefix, 0);
    assert(r4.first == 0 && r4.second == 0);

    std::cout << "18_Bishu_and_Soldiers tests passed.\n";
    return 0;
}
