#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> find(int arr[], int n, int x) {
    int start = 0, end = n - 1, mid, temp = -1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            temp = mid;
            break;
        } else if (arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (temp == -1) return {-1, -1};

    int first = temp, last = temp;
    while (first > 0 && arr[first - 1] == x) first--;
    while (last < n - 1 && arr[last + 1] == x) last++;

    return {first, last};
}

int main() {
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    vector<int> res = find(arr, n, x);
    cout << "First and last occurrences of " << x << ": [" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}
