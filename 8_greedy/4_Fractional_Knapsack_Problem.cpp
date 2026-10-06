#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool cmp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, cmp);
        double totalValue = 0.0;
        int curWeight = 0;

        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                totalValue += arr[i].value;
            } else {
                int remain = W - curWeight;
                totalValue += arr[i].value * ((double)remain / arr[i].weight);
                break;
            }
        }
        return totalValue;
    }
};

int main() {
    Solution sol;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Max fractional value: " << sol.fractionalKnapsack(50, arr, 3) << endl;
    return 0;
}
