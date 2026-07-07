#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    vector<vector<pair<int,int>>> graph(V);

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        graph[edges[i].u].push_back({edges[i].v, edges[i].w});
    }

    int src;
    cin >> src;

    vector<int> dist(V, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist > dist[u])
            continue;

        for (auto edge : graph[u]) {

            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;

                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++) {

        cout << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
