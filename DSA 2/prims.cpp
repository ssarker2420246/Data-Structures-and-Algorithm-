#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    // Undirected graph
    adj[0].push_back(make_pair(1,2));
    adj[1].push_back(make_pair(0,2));

    adj[0].push_back(make_pair(3,6));
    adj[3].push_back(make_pair(0,6));

    adj[1].push_back(make_pair(2,3));
    adj[2].push_back(make_pair(1,3));

    adj[1].push_back(make_pair(3,8));
    adj[3].push_back(make_pair(1,8));

    adj[1].push_back(make_pair(4,5));
    adj[4].push_back(make_pair(1,5));

    adj[2].push_back(make_pair(4,7));
    adj[4].push_back(make_pair(2,7));

    vector<bool> inMST(V, false);

    // pair<weight, vertex>
    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>> > pq;

    pq.push(make_pair(0, 0));

    int mstWeight = 0;

    while (!pq.empty()) {
        pair<int,int> topElement = pq.top();
        pq.pop();

        int weight = topElement.first;
        int u = topElement.second;

        if (inMST[u] == true)
            continue;

        inMST[u] = true;
        mstWeight += weight;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int wt = adj[u][i].second;

            if (inMST[v] == false) {
                pq.push(make_pair(wt, v));
            }
        }
    }

    cout << "Total MST weight: " << mstWeight << endl;

    return 0;
}
