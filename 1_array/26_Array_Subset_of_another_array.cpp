#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[a1[i]]++;
    for (int i = 0; i < m; i++) {
        if (freq[a2[i]] <= 0) return "No";
        freq[a2[i]]--;
    }
    return "Yes";
}

int main() {
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};
    cout << "Is a2 subset of a1: " << isSubset(a1, a2, 6, 4) << endl;
    return 0;
}
