#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

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
    std::cout << "Cloned graph node val: " << cloned->val << "\n";
    std::cout << "Neighbors of cloned node 1: ";
    for (Node* nb : cloned->neighbors) {
        std::cout << nb->val << " ";
    }
    std::cout << "\n";
    return 0;
}
