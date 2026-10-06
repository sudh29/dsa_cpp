#include <iostream>

using namespace std;

int square(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;

    int x = n >> 1;
    if (n & 1) { // odd: (2x+1)^2 = 4x^2 + 4x + 1 = 4(x^2 + x) + 1
        return ((square(x) + x) << 2) + 1;
    } else { // even: (2x)^2 = 4x^2
        return square(x) << 2;
    }
}

int main() {
    for (int n : {5, 7, 12, 15}) {
        cout << "Square of " << n << ": " << square(n) << endl;
    }
    return 0;
}
