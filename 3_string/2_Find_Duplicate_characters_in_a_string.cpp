#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printDups(const string &str) {
    unordered_map<char, int> count;
    for (char c : str) count[c]++;

    cout << "Duplicates in '" << str << "':\n";
    for (const auto &[ch, freq] : count) {
        if (freq > 1) {
            cout << "['" << ch << "', " << freq << "] ";
        }
    }
    cout << endl;
}

int main() {
    printDups("test string");
    return 0;
}
