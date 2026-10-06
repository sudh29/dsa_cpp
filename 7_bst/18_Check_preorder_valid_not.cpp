#include <cassert>
#include <climits>
#include <iostream>
#include <span>
#include <stack>
#include <vector>

bool canRepresentBST(std::span<const int> pre) {
    std::stack<int> s;
    int root = INT_MIN;

    for (int val : pre) {
        if (val < root) return false;
        while (!s.empty() && s.top() < val) {
            root = s.top();
            s.pop();
        }
        s.push(val);
    }
    return true;
}

int main() {
    std::vector<int> pre1 = {40, 30, 35, 80, 100};
    std::vector<int> pre2 = {40, 30, 35, 20, 80, 100};

    assert(canRepresentBST(pre1));
    assert(!canRepresentBST(pre2));

    std::vector<int> single = {10};
    assert(canRepresentBST(single));

    std::vector<int> empty;
    assert(canRepresentBST(empty));

    std::cout << "7_bst 18_Check_preorder_valid_not: All tests passed.\n";
    return 0;
}
