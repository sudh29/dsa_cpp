#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    int minimumNumberOfSwaps(std::string S) {
        std::vector<int> pos;
        for (int i = 0; i < static_cast<int>(S.length()); i++) {
            if (S[i] == '[') pos.push_back(i);
        }

        int count = 0, p = 0, swaps = 0;
        for (int i = 0; i < static_cast<int>(S.length()); i++) {
            if (S[i] == '[') {
                count++;
                p++;
            } else {
                count--;
            }

            if (count < 0) {
                swaps += (pos[p] - i);
                std::swap(S[i], S[pos[p]]);
                p++;
                count = 1;
            }
        }
        return swaps;
    }
};

int main() {
    Solution sol;
    assert(sol.minimumNumberOfSwaps("[]][][") == 2);
    assert(sol.minimumNumberOfSwaps("[[][]]") == 0);
    assert(sol.minimumNumberOfSwaps("][][") == 2);
    assert(sol.minimumNumberOfSwaps("[]") == 0);

    std::cout << "29_Minimum_swaps_bracket_balancing tests passed.\n";
    return 0;
}
