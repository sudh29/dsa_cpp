#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// Merge overlapping intervals and find the k-th smallest element
ll findKth(vector<pair<ll, ll>> intervals, ll k) {
    sort(intervals.begin(), intervals.end());
    vector<pair<ll, ll>> merged;
    for (const auto &cur : intervals) {
        if (merged.empty() || merged.back().second < cur.first) {
            merged.push_back(cur);
        } else {
            merged.back().second = max(merged.back().second, cur.second);
        }
    }

    for (const auto &p : merged) {
        ll count = p.second - p.first + 1;
        if (k <= count) {
            return p.first + k - 1;
        }
        k -= count;
    }
    return -1;
}

int main() {
    vector<pair<ll, ll>> intervals = {{1, 5}, {10, 15}};
    ll k = 6;
    cout << "Kth element (k=" << k << "): " << findKth(intervals, k) << endl;
    return 0;
}
