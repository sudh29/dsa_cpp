#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCyclic(int u, int parent, vector<bool> &visited, const vector<vector<int>> &adj) {
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

    bool isTree(int n, vector<vector<int>> adj) {
        vector<bool> visited(n, false);
        if (isCyclic(0, -1, visited, adj)) return false;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2, 3}; adj[1] = {0}; adj[2] = {0}; adj[3] = {0, 4}; adj[4] = {3};

    Solution sol;
    cout << "Is graph a valid tree: " << (sol.isTree(n, adj) ? "Yes" : "No") << endl;
    return 0;
}
