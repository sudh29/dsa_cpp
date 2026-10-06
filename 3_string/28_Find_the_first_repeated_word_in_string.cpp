#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

string firstRepeat(const string &s) {
    unordered_set<string> seen;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        if (seen.find(word) != seen.end()) return word;
        seen.insert(word);
    }
    return "NoRepetition";
}

int main() {
    string str = "Ravi had been saying that he would like to visit the alpine resort but Ravi forgot";
    cout << "First repeated word: " << firstRepeat(str) << endl;
    return 0;
}
