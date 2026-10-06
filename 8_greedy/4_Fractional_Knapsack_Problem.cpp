#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool cmp(const Item& a, const Item& b) {
        double r1 = static_cast<double>(a.value) / a.weight;
        double r2 = static_cast<double>(b.value) / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, std::vector<Item> arr) {
        std::sort(arr.begin(), arr.end(), cmp);
        double totalValue = 0.0;
        int curWeight = 0;

        for (const auto& item : arr) {
            if (curWeight + item.weight <= W) {
                curWeight += item.weight;
                totalValue += item.value;
            } else {
                int remain = W - curWeight;
                totalValue += item.value * (static_cast<double>(remain) / item.weight);
                break;
            }
        }
        return totalValue;
    }
};

int main() {
    Solution sol;
    std::vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    double val = sol.fractionalKnapsack(50, arr);
    assert(std::abs(val - 240.0) < 1e-6);

    assert(std::abs(sol.fractionalKnapsack(0, arr) - 0.0) < 1e-6);
    assert(std::abs(sol.fractionalKnapsack(50, {}) - 0.0) < 1e-6);

    std::cout << "4_Fractional_Knapsack_Problem tests passed.\n";
    return 0;
}
