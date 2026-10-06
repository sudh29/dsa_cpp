#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        int M = pat.length(), N = txt.length();
        int d = 256, q = 101;
        int p = 0, t = 0, h = 1;
        vector<int> res;

        for (int i = 0; i < M - 1; i++) h = (h * d) % q;

        for (int i = 0; i < M; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        for (int i = 0; i <= N - M; i++) {
            if (p == t) {
                bool match = true;
                for (int j = 0; j < M; j++) {
                    if (txt[i + j] != pat[j]) { match = false; break; }
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
    string txt = "GEEKS FOR GEEKS", pat = "GEEK";
    auto matches = sol.search(pat, txt);
    cout << "Rabin-Karp matches: ";
    for (int m : matches) cout << m << " ";
    cout << endl;
    return 0;
}
