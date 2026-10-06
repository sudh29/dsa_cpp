#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0), neighbors() {}
    Node(int _val) : val(_val), neighbors() {}
    Node(int _val, std::vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    std::unordered_map<Node*, Node*> visited;
    std::queue<Node*> q;

    visited[node] = new Node(node->val);
    q.push(node);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        for (Node* neighbor : curr->neighbors) {
            if (visited.find(neighbor) == visited.end()) {
                visited[neighbor] = new Node(neighbor->val);
                q.push(neighbor);
            }
            visited[curr]->neighbors.push_back(visited[neighbor]);
        }
    }
    return visited[node];
}

void freeGraph(Node* node) {
    if (!node) return;
    std::unordered_set<Node*> visited;
    std::queue<Node*> q;
    visited.insert(node);
    q.push(node);
    std::vector<Node*> all_nodes;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        all_nodes.push_back(curr);
        for (Node* nb : curr->neighbors) {
            if (visited.insert(nb).second) {
                q.push(nb);
            }
        }
    }
    for (Node* n : all_nodes) {
        delete n;
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* cloned = cloneGraph(node1);
    assert(cloned != nullptr);
    assert(cloned != node1);
    assert(cloned->val == 1);
    assert(cloned->neighbors.size() == 2);
    assert(cloned->neighbors[0]->val == 2);
    assert(cloned->neighbors[1]->val == 4);

    freeGraph(node1);
    freeGraph(cloned);

    assert(cloneGraph(nullptr) == nullptr);

    std::cout << "9_Clone_a_graph tests passed.\n";
    return 0;
}
