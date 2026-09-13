#include <bits/stdc++.h>

using namespace std;

int countSubsetSumK(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < k + 1; j++) {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << countSubsetSumK(arr, k) << "\n";

    return 0;
}