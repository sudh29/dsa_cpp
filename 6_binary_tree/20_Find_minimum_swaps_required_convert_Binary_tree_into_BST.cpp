#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void inorder(const vector<int> &a, int n, int index, vector<int> &ans) {
    if (index >= n) return;
    inorder(a, n, 2 * index + 1, ans);
    ans.push_back(a[index]);
    inorder(a, n, 2 * index + 2, ans);
}

int minSwaps(int n, vector<int> &A) {
    vector<int> ans;
    inorder(A, n, 0, ans);

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {ans[i], i};
    sort(v.begin(), v.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || v[i].second == i) continue;
        int cycle_size = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            cycle_size++;
        }
        if (cycle_size > 1) swaps += (cycle_size - 1);
    }
    return swaps;
}

int main() {
    vector<int> a = {5, 6, 7, 8, 9, 10, 11};
    cout << "Min swaps to convert binary tree to BST: " << minSwaps(a.size(), a) << endl;
    return 0;
}
