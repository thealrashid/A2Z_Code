#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int result = INT_MAX;

    vector<vector<int>> dp = triangle;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) dp[i][0] = triangle[i][0] + dp[i - 1][0];
            else if (j == i) dp[i][i] = triangle[i][j] + dp[i - 1][j - 1];
            else dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);

            if (i == n - 1) result = min(result, dp[i][j]);
        }
    }

    if (result == INT_MAX) result = dp[0][0];

    return result;
}

int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}