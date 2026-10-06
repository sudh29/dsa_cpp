#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

std::string firstRepeat(const std::string& s) {
    std::unordered_set<std::string> seen;
    std::stringstream ss(s);
    std::string word;
    while (ss >> word) {
        if (seen.find(word) != seen.end()) return word;
        seen.insert(word);
    }
    return "NoRepetition";
}

int main() {
    std::string str1 = "Ravi had been saying that he would like to visit the alpine resort but Ravi forgot";
    assert(firstRepeat(str1) == "Ravi");

    std::string str2 = "he had had he";
    assert(firstRepeat(str2) == "had");

    std::string str3 = "no repetition here at all";
    assert(firstRepeat(str3) == "NoRepetition");

    assert(firstRepeat("") == "NoRepetition");

    std::cout << "28_Find_the_first_repeated_word_in_string tests passed.\n";
    return 0;
}
