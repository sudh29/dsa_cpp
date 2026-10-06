#include <cassert>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

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
    std::vector<long long> arr1 = {4, 3, 2, 6};
    assert(minCost(arr1, static_cast<int>(arr1.size())) == 29);

    std::vector<long long> arr2 = {1, 2, 3};
    assert(minCost(arr2, static_cast<int>(arr2.size())) == 9);

    std::cout << "31_Minimum_Cost_ropes tests passed.\n";
    return 0;
}
