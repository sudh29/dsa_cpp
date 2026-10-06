#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxHistArea(const vector<int> &hist) {
    stack<int> s;
    int max_area = 0, n = hist.size();
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : hist[i];
        while (!s.empty() && hist[s.top()] >= h) {
            int height = hist[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }
    return max_area;
}

int maxRectangle(const vector<vector<int>> &mat) {
    if (mat.empty()) return 0;
    int r = mat.size(), c = mat[0].size();
    vector<int> hist(c, 0);
    int max_area = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            hist[j] = (mat[i][j] == 0) ? 0 : hist[j] + 1;
        }
        max_area = max(max_area, maxHistArea(hist));
    }
    return max_area;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };
    cout << "Max rectangle area: " << maxRectangle(mat) << endl;
    return 0;
}
