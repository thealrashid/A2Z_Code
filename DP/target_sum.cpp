#include<bits/stdc++.h>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    int k;

    for (int i = 0; i < n; i++) sum += nums[i];

    if (abs(target) > sum) return 0;
    if ((target + sum) % 2 != 0) return 0;
    k = (target + sum) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];

            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][k];
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << findTargetSumWays(nums, target) << "\n";

    return 0;
}