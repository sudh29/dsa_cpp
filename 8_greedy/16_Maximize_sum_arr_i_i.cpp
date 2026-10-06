#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

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
    assert(Maximize(a1, static_cast<int>(a1.size())) == 40);

    std::vector<int> a2 = {1, 2, 3};
    assert(Maximize(a2, static_cast<int>(a2.size())) == 8);

    std::cout << "16_Maximize_sum_arr_i_i tests passed.\n";
    return 0;
}
