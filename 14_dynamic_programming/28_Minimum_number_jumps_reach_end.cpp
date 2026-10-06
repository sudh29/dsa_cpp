#include <iostream>
#include <vector>
#include <algorithm>

int minJumps(const std::vector<int>& arr, int n) {
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;

    int jumps = 0;
    int current_end = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = std::max(farthest, i + arr[i]);
        if (i == current_end) {
            jumps++;
            current_end = farthest;
            if (current_end >= n - 1) return jumps;
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    std::cout << "Min jumps: " << minJumps(arr, arr.size()) << " (expected 3)\n";
    return 0;
}
