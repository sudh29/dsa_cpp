#include <cassert>
#include <iostream>

long long towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n <= 0) return 0;
    if (n == 1) {
        return 1;
    }
    long long count = 0;
    count += towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    count += 1;
    count += towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    return count;
}

int main() {
    assert(towerOfHanoi(3, 'A', 'C', 'B') == 7);
    assert(towerOfHanoi(4, 'A', 'C', 'B') == 15);
    assert(towerOfHanoi(1, 'A', 'C', 'B') == 1);
    assert(towerOfHanoi(0, 'A', 'C', 'B') == 0);

    std::cout << "tower_of_hanoi tests passed.\n";
    return 0;
}
