#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool validShuffle(string str1, string str2, string shuffle) {
    if (str1.length() + str2.length() != shuffle.length()) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    sort(shuffle.begin(), shuffle.end());

    string combined = str1 + str2;
    sort(combined.begin(), combined.end());
    return combined == shuffle;
}

int main() {
    string s1 = "XY", s2 = "12", sh = "1X2Y";
    cout << "Valid shuffle: " << (validShuffle(s1, s2, sh) ? "Yes" : "No") << endl;
    return 0;
}
