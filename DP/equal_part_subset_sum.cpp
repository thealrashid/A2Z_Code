#include <bits/stdc++.h>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) sum += nums[i];
    
    if (sum % 2 != 0) return false;

    int target = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < target + 1; j++) {
            dp[i][j] = dp[i - 1][j];

            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};

    cout << canPartition(nums) << "\n";

    return 0;
}