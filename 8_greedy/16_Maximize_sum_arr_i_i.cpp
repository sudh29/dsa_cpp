#include <iostream>
#include <vector>
#include <algorithm>

long long Maximize(std::vector<int>& a, int n) {
    long long mod = 1000000007;
    std::sort(a.begin(), a.end());
    long long sum_total = 0;
    for (int i = 0; i < n; ++i) {
        sum_total = (sum_total + 1LL * a[i] * i) % mod;
    }
    return sum_total;
}

int main() {
    std::vector<int> a1 = {5, 3, 2, 4, 1};
    std::cout << "Max sum: " << Maximize(a1, a1.size()) << " (expected 40)\n";
    return 0;
}
