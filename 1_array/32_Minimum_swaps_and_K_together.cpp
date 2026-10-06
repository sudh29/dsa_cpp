#include <iostream>
#include <algorithm>

using namespace std;

int minSwap(int arr[], int n, int k) {
    int good = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) good++;
    }

    int bad = 0;
    for (int i = 0; i < good; i++) {
        if (arr[i] > k) bad++;
    }

    int ans = bad;
    for (int i = 0, j = good; j < n; i++, j++) {
        if (arr[i] > k) bad--;
        if (arr[j] > k) bad++;
        ans = min(ans, bad);
    }
    return ans;
}

int main() {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "Min swaps to bring elements <= " << k << " together: " << minSwap(arr, n, k) << endl;
    return 0;
}
