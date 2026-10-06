#include <cassert>
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
            ans[i] = static_cast<char>('0' + S);
            S = 0;
        }
    }
    // Most significant digit gets remaining S + 1
    ans[0] = static_cast<char>('1' + S);

    return std::string(ans.begin(), ans.end());
}

int main() {
    assert(smallestNumber(9, 2) == "18");
    assert(smallestNumber(20, 3) == "299");
    assert(smallestNumber(25, 2) == "-1");
    assert(smallestNumber(0, 1) == "0");
    assert(smallestNumber(1, 1) == "1");

    std::cout << "32_Find_smallest_number_given_number_digits_sum_digits tests passed.\n";
    return 0;
}
