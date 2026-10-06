#include <cassert>
#include <iostream>
#include <vector>

class Solution {
private:
    bool isCyclic(int u, int parent, std::vector<bool> &visited, const std::vector<std::vector<int>> &adj) const {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                if (isCyclic(v, u, visited, adj)) return true;
            } else if (v != parent) {
                return true;
            }
        }
        return false;
    }

public:
    bool isTree(int n, const std::vector<std::vector<int>> &adj) const {
        if (n <= 0) return true;
        std::vector<bool> visited(n, false);
        if (isCyclic(0, -1, visited, adj)) return false;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
};

int main() {
    int n1 = 5;
    std::vector<std::vector<int>> adj1(n1);
    adj1[0] = {1, 2, 3}; adj1[1] = {0}; adj1[2] = {0}; adj1[3] = {0, 4}; adj1[4] = {3};

    Solution sol;
    assert(sol.isTree(n1, adj1));

    // Graph with a cycle
    int n2 = 3;
    std::vector<std::vector<int>> adj2(n2);
    adj2[0] = {1, 2}; adj2[1] = {0, 2}; adj2[2] = {0, 1};
    assert(!sol.isTree(n2, adj2));

    std::cout << "6_binary_tree 26_Check_graph_tree_or_not: All tests passed.\n";
    return 0;
}
