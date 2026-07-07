#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 3, 4};
    int amount = 6;

    vector<int> dp(amount + 1, INT_MIN);
    vector<int> lastCoin(amount + 1, -1);

    dp[0] = 0;

    for(int a = 1; a <= amount; a++) {
        for(int coin : coins) {
            if(a - coin >= 0 && dp[a - coin] != INT_MAX) {
                if(1 + dp[a - coin] > dp[a]) {
                    dp[a] = min(dp[a],1 + dp[a - coin]);
                    lastCoin[a] = coin;
                }
            }
        }
    }

    if(dp[amount] == INT_MIN) {
        cout << "Not possible\n";
    }
    else {
        cout << "Minimum coins: " << dp[amount] << endl;

        cout << "Coins chosen: ";

        int currentAmount = amount;

        while(currentAmount > 0) {
            int coin = lastCoin[currentAmount];
            cout << coin << " ";
            currentAmount -= coin;
        }

        cout << endl;
    }

    return 0;
}
