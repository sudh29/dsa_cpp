#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class IterativeGraph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adj;

public:
    void addEdge(const std::string& u, const std::string& v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::string> bfs(const std::string& start) {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();
            res.push_back(curr);

            for (const auto& neighbor : adj[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return res;
    }

    std::vector<std::string> dfs(const std::string& start) {
        std::vector<std::string> res;
        std::unordered_set<std::string> visited;
        std::stack<std::string> s;

        s.push(start);

        while (!s.empty()) {
            std::string curr = s.top();
            s.pop();

            if (visited.find(curr) == visited.end()) {
                visited.insert(curr);
                res.push_back(curr);

                // push neighbors in reverse order to explore first neighbor first
                for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        s.push(*it);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    IterativeGraph g;
    g.addEdge("0", "1");
    g.addEdge("0", "2");
    g.addEdge("1", "3");
    g.addEdge("1", "4");
    g.addEdge("2", "4");
    g.addEdge("3", "4");

    auto b = g.bfs("0");
    assert(b.size() == 5);
    assert(b[0] == "0");

    auto d = g.dfs("0");
    assert(d.size() == 5);
    assert(d[0] == "0");

    std::cout << "graph_iterative_bfs_dfs tests passed.\n";
    return 0;
}
