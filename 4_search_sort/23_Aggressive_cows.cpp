#include <algorithm>
#include <cassert>
#include <iostream>
#include <span>
#include <vector>

bool canPlace(std::span<const int> stalls, int cows, int minDist) {
    int count = 1;
    int last = stalls[0];
    for (size_t i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= minDist) {
            count++;
            last = stalls[i];
            if (count >= cows) return true;
        }
    }
    return false;
}

int largestMinDistance(std::vector<int> stalls, int cows) {
    if (stalls.empty() || cows <= 0) return 0;
    std::sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::vector<int> stalls1 = {1, 2, 8, 4, 9};
    assert(largestMinDistance(stalls1, 3) == 3);

    std::vector<int> stalls2 = {1, 2, 3, 4, 5};
    assert(largestMinDistance(stalls2, 2) == 4);

    std::vector<int> stalls3 = {10, 1, 2, 7, 5};
    assert(largestMinDistance(stalls3, 3) == 4);

    std::cout << "23_Aggressive_cows tests passed.\n";
    return 0;
}
