#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Demonstration with pre-configured test data
    int n = 7;
    vector<int> soldiers = {1, 2, 3, 4, 5, 6, 7};
    sort(soldiers.begin(), soldiers.end());

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + soldiers[i];

    vector<int> queries = {3, 10, 2};
    cout << "=== Bishu and Soldiers Query Results ===\n";
    for (int power : queries) {
        int idx = upper_bound(soldiers.begin(), soldiers.end(), power) - soldiers.begin();
        cout << "Power " << power << " -> Defeated: " << idx << ", Cumulative Strength: " << prefix[idx] << endl;
    }
    return 0;
}
