#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;

        for (int j = 1; j <= amount; j++) {
            dp[i][j] = dp[i - 1][j];

            if (coins[i - 1] <= j && dp[i][j - coins[i - 1]] != INF) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }

    return dp[n][amount] == INF ? -1 : dp[n][amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << coinChange(coins, amount) << "\n";

    return 0;
}