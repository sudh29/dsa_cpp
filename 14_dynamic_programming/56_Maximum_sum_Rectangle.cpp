#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int kadane(const std::vector<int>& arr) {
    int max_so_far = arr[0];
    int curr = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        curr = std::max(arr[i], curr + arr[i]);
        max_so_far = std::max(max_so_far, curr);
    }
    return max_so_far;
}

int maximumSumRectangle(int R, int C, const std::vector<std::vector<int>>& M) {
    int max_sum = INT_MIN;

    for (int top = 0; top < R; ++top) {
        std::vector<int> temp(C, 0);
        for (int bottom = top; bottom < R; ++bottom) {
            for (int i = 0; i < C; ++i) {
                temp[i] += M[bottom][i];
            }
            max_sum = std::max(max_sum, kadane(temp));
        }
    }
    return max_sum;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    std::cout << "Max sum rectangle: " << maximumSumRectangle(4, 5, mat) << " (expected 29)\n";
    return 0;
}
