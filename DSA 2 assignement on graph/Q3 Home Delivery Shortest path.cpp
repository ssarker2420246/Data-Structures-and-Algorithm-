#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>> &adj)
{
    int n = adj.size();

    vector<int> dist(n, INT_MAX);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u])
            continue;

        for(auto edge : adj[u])
        {
            int v = edge.first;
            int wt = edge.second;

            if(dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<pair<int,int>>> adj(N);

    vector<vector<int>> T(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> T[i][j];

            if(i != j)
            {
                adj[i].push_back({j, T[i][j]});
            }
        }
    }

    int M;
    cin >> M;

    while(M--)
    {
        int S, G, D;
        cin >> S >> G >> D;

        vector<int> distS = dijkstra(S, adj);
        vector<int> distG = dijkstra(G, adj);

        int deliveryBoyTime =
            distS[G] + distG[D];

        int directTime =
            distS[D];

        int saved =
            deliveryBoyTime - directTime;

        cout << deliveryBoyTime
             << " "
             << saved
             << endl;
    }

    return 0;
}
