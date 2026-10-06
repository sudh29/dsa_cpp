#include <iostream>
#include <vector>

long long countSubArrayProductLessThanK(const std::vector<int>& a, int n, long long k) {
    if (k <= 1) return 0;
    long long prod = 1;
    long long count = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        prod *= a[end];
        while (start <= end && prod >= k) {
            prod /= a[start++];
        }
        count += (end - start + 1);
    }
    return count;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    int k = 10;
    std::cout << "Subarrays with product < 10: " << countSubArrayProductLessThanK(a, a.size(), k) << " (expected 7)\n";
    return 0;
}
