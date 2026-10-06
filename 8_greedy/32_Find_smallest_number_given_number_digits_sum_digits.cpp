#include <iostream>
#include <string>
#include <vector>

std::string smallestNumber(int S, int D) {
    if (9 * D < S) return "-1";
    if (S == 0) {
        return (D == 1) ? "0" : "-1";
    }

    std::vector<char> ans(D, '0');
    // Reserve 1 for the most significant digit (index 0)
    S -= 1;

    for (int i = D - 1; i > 0; --i) {
        if (S > 9) {
            ans[i] = '9';
            S -= 9;
        } else {
            ans[i] = '0' + S;
            S = 0;
        }
    }
    // Most significant digit gets remaining S + 1
    ans[0] = '1' + S;

    return std::string(ans.begin(), ans.end());
}

int main() {
    std::cout << "Smallest number (S=9, D=2): " << smallestNumber(9, 2) << " (expected 18)\n";
    std::cout << "Smallest number (S=20, D=3): " << smallestNumber(20, 3) << " (expected 299)\n";
    std::cout << "Smallest number (S=25, D=2): " << smallestNumber(25, 2) << " (expected -1)\n";
    return 0;
}
