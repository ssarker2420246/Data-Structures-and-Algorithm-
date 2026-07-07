#include <bits/stdc++.h>
using namespace std;

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
            parent[x] = find(parent[x]);
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

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    DSU dsu(n);

    for (auto edge : edges) {
        dsu.unite(edge[0], edge[1]);
    }

    return dsu.find(source) == dsu.find(destination);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int source, destination;
    cin >> source >> destination;

    if (validPath(n, edges, source, destination)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
