#include <iostream>
#include <vector>
#include <queue>

long long minCost(std::vector<long long>& arr, int n) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(arr[i]);
    }
    long long res = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long cost = a + b;
        res += cost;
        pq.push(cost);
    }
    return res;
}

int main() {
    std::vector<long long> arr = {4, 3, 2, 6};
    std::cout << "Min cost connecting ropes: " << minCost(arr, arr.size()) << " (expected 29)\n";
    return 0;
}
