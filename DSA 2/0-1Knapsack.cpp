#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> wt = {2, 3, 4, 5};
    vector<int> val = {3, 4, 5, 6};
    int W = 7;

    int n = wt.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];

            if(wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << endl;

    int w = W;
    vector<int> takenObjects;

    for(int i = n; i >= 1; i--) {
        if(dp[i][w] != dp[i - 1][w]) {
            takenObjects.push_back(i - 1);
            w -= wt[i - 1];
        }
    }

    reverse(takenObjects.begin(), takenObjects.end());

    cout << "Objects taken: ";
    for(int index : takenObjects) {
        cout << index << " ";
    }

    cout << endl;

    return 0;
}
