#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
    std::vector<int> parent, rank;
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                std::swap(root_i, root_j);
            parent[root_j] = root_i;
            if (rank[root_i] == rank[root_j])
                rank[root_i]++;
            return true;
        }
        return false;
    }
};

int kruskalMST(int V, std::vector<Edge>& edges) {
    if (V <= 1) return 0;
    std::sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mst_weight = 0;
    int edges_count = 0;

    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.weight;
            edges_count++;
            if (edges_count == V - 1) break;
        }
    }
    return mst_weight;
}

int main() {
    int V = 4;
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    assert(kruskalMST(V, edges) == 19);

    std::vector<Edge> empty;
    assert(kruskalMST(0, empty) == 0);

    std::cout << "18_Implement_Kruskals_Algorithm tests passed.\n";
    return 0;
}
