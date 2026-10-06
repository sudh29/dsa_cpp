#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::string kthPermutation(int n, int k) {
    int fact = 1;
    std::vector<int> numbers;
    for (int i = 1; i < n; ++i) {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);

    std::string ans;
    k = k - 1; // 0-based indexing

    while (true) {
        ans += std::to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + (k / fact));
        if (numbers.empty()) break;
        k = k % fact;
        fact = fact / static_cast<int>(numbers.size());
    }
    return ans;
}

int main() {
    assert(kthPermutation(3, 3) == "213");
    assert(kthPermutation(4, 4) == "1342");
    assert(kthPermutation(1, 1) == "1");
    assert(kthPermutation(3, 1) == "123");

    std::cout << "18_Find_K-th_Permutation_Sequence_first_N_natural_numbers tests passed.\n";
    return 0;
}
