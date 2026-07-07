#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int source = 1;

    vector<pair<int, int>> graph[n + 1];

    // Directed edges: u -> v with weight w
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 4});
    graph[2].push_back({3, 1});
    graph[2].push_back({4, 7});
    graph[3].push_back({5, 3});
    graph[4].push_back({5, 1});

    vector<int> dist(n + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int currentDistance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto x : graph[node]) {
            int nextNode = x.first;
            int weight = x.second;

            if(currentDistance + weight < dist[nextNode]) {
                dist[nextNode] = currentDistance + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << "Directed Graph Shortest Distances:\n";

    for(int i = 1; i <= n; i++) {
        cout << "Distance from " << source << " to " << i << " = ";

        if(dist[i] == INT_MAX)
            cout << "Not reachable\n";
        else
            cout << dist[i] << endl;
    }

    return 0;
}
