#include <iostream>
#include <vector>
#include <algorithm>

int alternatingMaxLength(const std::vector<int>& arr) {
    if (arr.empty()) return 0;
    int up = 1, down = 1;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1;
        }
    }
    return std::max(up, down);
}

int main() {
    std::vector<int> arr = {1, 5, 4};
    std::cout << "Max alternating subsequence length: " << alternatingMaxLength(arr) << " (expected 3)\n";
    return 0;
}
