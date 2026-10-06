#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        while (res.length() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }

    string solve(int arr[], int n) {
        sort(arr, arr + n);
        string n1 = "", n2 = "";
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) n1 += to_string(arr[i]);
            else n2 += to_string(arr[i]);
        }
        return addStrings(n1, n2);
    }
};

int main() {
    Solution sol;
    int arr[] = {6, 8, 4, 5, 2, 3};
    cout << "Minimum sum of two formed numbers: " << sol.solve(arr, 6) << endl;
    return 0;
}
