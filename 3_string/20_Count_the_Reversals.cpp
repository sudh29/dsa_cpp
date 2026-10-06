#include <cassert>
#include <iostream>
#include <string_view>

int countRev(std::string_view s) {
    if (s.length() % 2 != 0) return -1;
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '{') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    return (open + 1) / 2 + (close + 1) / 2;
}

int main() {
    assert(countRev("}{{}}{{{") == 3);
    assert(countRev("}{") == 2);
    assert(countRev("{{}") == -1);
    assert(countRev("{{{{") == 2);
    assert(countRev("{{}{{{}}") == 1);
    assert(countRev("") == 0);

    std::cout << "20_Count_the_Reversals tests passed.\n";
    return 0;
}
