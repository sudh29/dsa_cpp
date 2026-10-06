#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

class Solution {
public:
    std::vector<int> search(std::string_view pat, std::string_view txt) {
        int M = static_cast<int>(pat.length());
        int N = static_cast<int>(txt.length());
        if (M == 0 || N < M) return {};

        int d = 256, q = 101;
        int p = 0, t = 0, h = 1;
        std::vector<int> res;

        for (int i = 0; i < M - 1; i++) {
            h = (h * d) % q;
        }

        for (int i = 0; i < M; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        for (int i = 0; i <= N - M; i++) {
            if (p == t) {
                bool match = true;
                for (int j = 0; j < M; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) res.push_back(i + 1); // 1-based indexing
            }
            if (i < N - M) {
                t = (d * (t - txt[i] * h) + txt[i + M]) % q;
                if (t < 0) t += q;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::string_view txt = "GEEKS FOR GEEKS", pat = "GEEK";
    auto matches = sol.search(pat, txt);
    std::vector<int> expected = {1, 11};
    assert(matches == expected);

    std::string_view txt2 = "AABAACAADAABAABA", pat2 = "AABA";
    std::vector<int> expected2 = {1, 10, 13};
    assert(sol.search(pat2, txt2) == expected2);

    assert(sol.search("XYZ", "ABC").empty());

    std::cout << "17_Rabin_Karp_Algo tests passed.\n";
    return 0;
}
