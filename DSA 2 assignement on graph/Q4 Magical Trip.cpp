#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>> &adj)
{
    int n = adj.size() - 1;

    vector<int> dist(n + 1, INT_MAX);

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
    int T;
    cin >> T;

    while(T--)
    {
        int N, M, L;
        cin >> N >> M >> L;

        vector<int> B(L);

        for(int i = 0; i < L; i++)
            cin >> B[i];

        vector<vector<pair<int,int>>> adj(N + 1);

        for(int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dist(N + 1);

        for(int i = 1; i <= N; i++)
        {
            dist[i] = dijkstra(i, adj);
        }

        int K = 1;
        int last = B[0];


        for(int i = 1; i < L - 1; i++)
        {
            if(dist[last][B[i + 1]] ==
               dist[last][B[i]] +
               dist[B[i]][B[i + 1]])
            {
                continue;
            }
            else
            {
                K++;
                last = B[i];
            }
        }

        K++;

        cout << K << endl;
    }

    return 0;
}
