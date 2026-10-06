#include <cassert>
#include <iostream>
#include <span>
#include <vector>

void rotate(std::span<int> arr) {
    if (arr.size() <= 1) return;
    int last = arr.back();
    for (size_t i = arr.size() - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    rotate(arr);
    std::vector<int> expected = {5, 1, 2, 3, 4};
    assert(arr == expected);

    std::vector<int> single = {10};
    rotate(single);
    assert(single == (std::vector<int>{10}));

    std::cout << "1_array 6_Cyclically_rotate_an_array_by_one: All tests passed.\n";
    return 0;
}
