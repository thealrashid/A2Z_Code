#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int capacity) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];

            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 4, 5, 6};
    int capacity = 5;

    cout << knapsack(weight, value, capacity) << "\n";

    return 0;
}