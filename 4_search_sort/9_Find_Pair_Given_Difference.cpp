#include <iostream>
#include <algorithm>

using namespace std;

bool findPair(int arr[], int size, int n) {
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size && j < size) {
        if (i != j && arr[j] - arr[i] == n) {
            return true;
        } else if (arr[j] - arr[i] < n) {
            j++;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    int arr[] = {5, 20, 3, 2, 5, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int diff = 78;
    cout << "Pair with difference " << diff << " exists: " << (findPair(arr, size, diff) ? "Yes" : "No") << endl;
    return 0;
}
