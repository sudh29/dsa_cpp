#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

class IterativeGraph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adj;

public:
    void addEdge(const std::string& u, const std::string& v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(const std::string& start) {
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        visited.insert(start);
        q.push(start);

        std::cout << "Iterative BFS: ";
        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();
            std::cout << curr << " ";

            for (const auto& neighbor : adj[curr]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }

    void dfs(const std::string& start) {
        std::unordered_set<std::string> visited;
        std::stack<std::string> s;

        s.push(start);

        std::cout << "Iterative DFS: ";
        while (!s.empty()) {
            std::string curr = s.top();
            s.pop();

            if (visited.find(curr) == visited.end()) {
                visited.insert(curr);
                std::cout << curr << " ";

                // push neighbors in reverse order to explore first neighbor first
                for (auto it = adj[curr].rbegin(); it != adj[curr].rend(); ++it) {
                    if (visited.find(*it) == visited.end()) {
                        s.push(*it);
                    }
                }
            }
        }
        std::cout << "\n";
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

    g.bfs("0");
    g.dfs("0");
    return 0;
}
