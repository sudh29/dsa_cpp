#include <iostream>
#include <string>

using namespace std;

int countRev(string s) {
    if (s.length() % 2 != 0) return -1;
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '{') {
            open++;
        } else {
            if (open > 0) open--;
            else close++;
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    string s = "}{{}}{{{";
    cout << "Reversals needed for " << s << ": " << countRev(s) << endl;
    return 0;
}
