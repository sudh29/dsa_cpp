#include <iostream>

using namespace std;

void rotate(int arr[], int n) {
    if (n <= 1) return;
    int last = arr[n - 1];
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, n);
    cout << "Cyclically rotated by one: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
