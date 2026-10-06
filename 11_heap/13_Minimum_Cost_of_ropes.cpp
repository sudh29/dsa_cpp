#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (long long i = 0; i < n; i++) pq.push(arr[i]);

        long long totalCost = 0;
        while (pq.size() > 1) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            long long cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        return totalCost;
    }
};

int main() {
    Solution sol;
    long long ropes[] = {4, 3, 2, 6};
    cout << "Min cost of connecting ropes: " << sol.minCost(ropes, 4) << endl;
    return 0;
}
