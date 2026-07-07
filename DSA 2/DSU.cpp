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

int main() {
    DSU dsu(5);  // create 5 elements: 0 to 4

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    cout << dsu.find(0) << endl;
    cout << dsu.find(2) << endl;

    if (dsu.find(0) == dsu.find(2)) {
        cout << "0 and 2 are in same set" << endl;
    } else {
        cout << "0 and 2 are NOT in same set" << endl;
    }

    return 0;
}
