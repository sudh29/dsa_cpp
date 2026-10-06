#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int a, b;
};

int maxChainLen(std::vector<Pair>& p, int n) {
    if (n == 0) return 0;
    std::sort(p.begin(), p.end(), [](const Pair& x, const Pair& y) {
        return x.b < y.b;
    });

    int count = 1;
    int last_end = p[0].b;

    for (int i = 1; i < n; ++i) {
        if (p[i].a > last_end) {
            count++;
            last_end = p[i].b;
        }
    }
    return count;
}

int main() {
    std::vector<Pair> p = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    std::cout << "Max length chain: " << maxChainLen(p, p.size()) << " (expected 3)\n";
    return 0;
}
