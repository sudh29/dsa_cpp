#include <cassert>
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& image, int r, int c, int oldColor, int newColor) {
    if (r < 0 || r >= static_cast<int>(image.size()) || c < 0 || c >= static_cast<int>(image[0].size())) {
        return;
    }
    if (image[r][c] != oldColor) return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, oldColor, newColor);
    dfs(image, r - 1, c, oldColor, newColor);
    dfs(image, r, c + 1, oldColor, newColor);
    dfs(image, r, c - 1, oldColor, newColor);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
    if (image.empty() || image[0].empty()) return image;
    int oldColor = image[sr][sc];
    if (oldColor != newColor) {
        dfs(image, sr, sc, oldColor, newColor);
    }
    return image;
}

int main() {
    std::vector<std::vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;
    auto result = floodFill(image, sr, sc, newColor);
    std::vector<std::vector<int>> expected = {
        {2, 2, 2},
        {2, 2, 0},
        {2, 0, 1}
    };
    assert(result == expected);

    std::vector<std::vector<int>> empty;
    assert(floodFill(empty, 0, 0, 1).empty());

    std::cout << "8_Flood_fill_algo tests passed.\n";
    return 0;
}
