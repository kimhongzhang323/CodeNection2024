#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Find function for Union-Find
int find(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
}

// Union function for Union-Find
void unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    // Initialize Union-Find structure
    iota(parent.begin(), parent.end(), 0);

    int redundantEdges = 0;

    // Read edges and process union-find
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (find(parent, u) == find(parent, v)) {
            // If the two nodes are already connected, it's a redundant edge
            redundantEdges++;
        } else {
            // Otherwise, unite the two components
            unite(parent, rank, u, v);
        }
    }

    // Count connected components
    int connectedComponents = 0;
    for (int i = 1; i <= n; ++i) {
        if (find(parent, i) == i) {
            connectedComponents++;
        }
    }

    // Bridges to burn: redundant edges
    // Bridges to add: (connectedComponents - 1)
    cout << redundantEdges << " " << (connectedComponents - 1) << endl;

    return 0;
}
