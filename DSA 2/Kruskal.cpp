#include <bits/stdc++.h>
using namespace std;

// Your DSU Class implementation
class DSU {
    vector<int> parent, rankArr;

public:
    DSU(int n) {
        parent.resize(n);
        rankArr.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path Compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rankArr[px] < rankArr[py]) {
            parent[px] = py;
        }
        else if (rankArr[px] > rankArr[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rankArr[px]++;
        }
    }
};

struct Edge {
    int u;
    int v;
    int w;
};

// Comparator function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int V = 5;

    vector<Edge> edges;
    edges.push_back({0,1,2});
    edges.push_back({0,3,6});
    edges.push_back({1,2,3});
    edges.push_back({1,3,8});
    edges.push_back({1,4,5});
    edges.push_back({2,4,7});

    // 1. Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // 2. Initialize the DSU structure for V vertices
    DSU dsu(V);
    int mstWeight = 0;

    cout << "Edges in the constructed MST:" << endl;

    // 3. Iterate through all sorted edges
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // Check if the current edge forms a cycle
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v); // Merge the components
            mstWeight += w;  // Add edge weight to total sum
            cout << u << " - " << v << " : " << w << endl;
        }
    }

    cout << "Total MST weight: " << mstWeight << endl;

    return 0;
}
