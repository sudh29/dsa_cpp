#include <iostream>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << from_rod << " to " << to_rod << "\n";
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << "\n";
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3;
    std::cout << "Tower of Hanoi moves for n = " << n << ":\n";
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
