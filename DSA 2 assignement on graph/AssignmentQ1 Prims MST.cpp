#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>, int>> calculatePrimsMST(
    int n, int m, vector<pair<pair<int,int>, int>> &g
) {
    vector<vector<pair<int,int>>> adj(n + 1);

    for (auto edge : g) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> inMST(n + 1, false);
    vector<int> parent(n + 1, -1);

    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    // {weight, node, parent}
    pq.push({0, 1, -1});

    vector<pair<pair<int,int>, int>> mst;

    while (!pq.empty()) {
        auto [weight, u, par] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        parent[u] = par;

        if (par != -1) {
            mst.push_back({{par, u}, weight});
        }

        for (auto x : adj[u]) {
            int v = x.first;
            int wt = x.second;

            if (!inMST[v]) {
                pq.push({wt, v, u});
            }
        }
    }

    return mst;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<pair<int,int>, int>> graph;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph.push_back({{u, v}, w});
        }

        vector<pair<pair<int,int>, int>> ans = calculatePrimsMST(n, m, graph);

        for (auto edge : ans) {
            cout << edge.first.first << " "
                 << edge.first.second << " "
                 << edge.second << endl;
        }
    }

    return 0;
}
