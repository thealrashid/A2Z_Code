#include <bits/stdc++.h>

using namespace std;

int paintWalls(vector<int>& cost, vector<int>& time) {
    int n = cost.size();
    const int INF = 1e9;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];

            int remaining = j - (1 + time[i - 1]);

            if (remaining <= 0) {
                dp[i][j] = min(dp[i][j], cost[i - 1]);
            } else {
                dp[i][j] = min(dp[i][j], cost[i - 1] + dp[i - 1][remaining]);
            }
        }
    }

    return dp[n][n];
}

int main() {
    vector<int> cost = {1, 2, 3, 2};
    vector<int> time = {1, 2, 3, 2};

    cout << paintWalls(cost, time) << "\n";

    return 0;
}