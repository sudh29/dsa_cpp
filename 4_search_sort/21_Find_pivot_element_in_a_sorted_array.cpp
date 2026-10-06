#include <iostream>

using namespace std;

int getPivotElement(int *arr, int left, int right) {
    if (right < left) return -1;
    if (right == left) return left;

    int mid = left + (right - left) / 2;
    if (mid < right && arr[mid] > arr[mid + 1])
        return mid + 1;
    if (mid > left && arr[mid] < arr[mid - 1])
        return mid;

    if (arr[right] > arr[mid])
        return getPivotElement(arr, left, mid - 1);
    return getPivotElement(arr, mid + 1, right);
}

int main() {
    int arr[] = {4, 5, 6, 7, 8, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivot = getPivotElement(arr, 0, n - 1);
    cout << "Pivot index: " << pivot << " (value: " << arr[pivot] << ")" << endl;
    return 0;
}
