#include <iostream>
#include <vector>
#include <cmath>

long long calculateWorkUnits(int N, const std::vector<long long>& demands) {
    long long total_work_units = 0;
    long long net_demand = 0;
    for (int i = 0; i < N; ++i) {
        net_demand += demands[i];
        total_work_units += std::abs(net_demand);
    }
    return total_work_units;
}

int main() {
    std::vector<long long> demands = {5, -4, 1, -3, 1};
    std::cout << "GERGOVIA wine trading work units: " << calculateWorkUnits(demands.size(), demands) << " (expected 9)\n";

    std::vector<long long> demands2 = {-1000, -1000, -1000, 3000};
    std::cout << "GERGOVIA work units 2: " << calculateWorkUnits(demands2.size(), demands2) << " (expected 6000)\n";
    return 0;
}
