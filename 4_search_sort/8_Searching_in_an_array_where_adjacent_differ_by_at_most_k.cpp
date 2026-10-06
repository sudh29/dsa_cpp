#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int search(int arr[], int n, int x, int k) {
    int i = 0;
    while (i < n) {
        if (arr[i] == x) return i;
        i += max(1, abs(arr[i] - x) / k);
    }
    return -1;
}

int main() {
    int arr[] = {4, 5, 6, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6, k = 1;
    cout << "Index of " << x << ": " << search(arr, n, x, k) << endl;
    return 0;
}
