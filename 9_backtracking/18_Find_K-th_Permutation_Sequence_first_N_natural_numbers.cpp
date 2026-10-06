#include <iostream>
#include <vector>
#include <string>

std::string kthPermutation(int n, int k) {
    int fact = 1;
    std::vector<int> numbers;
    for (int i = 1; i < n; ++i) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    std::string ans = "";
    k = k - 1; // 0-based indexing

    while (true) {
        ans += std::to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if (numbers.empty()) break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}

int main() {
    std::cout << "3rd permutation of N=3: " << kthPermutation(3, 3) << " (expected 213)\n";
    std::cout << "4th permutation of N=4: " << kthPermutation(4, 4) << " (expected 1342)\n";
    return 0;
}
