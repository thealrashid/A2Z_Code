#include <bits/stdc++.h>

using namespace std;

int countSubsetSumK(vector<int>& arr, int k) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];

            if (arr[i - 1] <= j) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}

int countPartitions(vector<int>& arr, int D) {
    if (D < 0) {
        return 0;
    }
    
    int total = 0;

    for (int x : arr) {
        total += x;
    }

    if (D > total || (total + D) % 2 != 0) {
        return 0;
    }

    int k = (total + D) / 2;

    return countSubsetSumK(arr, k);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int D = 2;

    cout << countPartitions(arr, D) << "\n";

    return 0;
}