#include <bits/stdc++.h>

using namespace std;

int jump_util(int n, vector<int>& height, vector<int>& dp, int k) {
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int min_cost = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                min_cost = min(min_cost, jump);
            }
        }

        dp[i] = min_cost;
    }

    return dp[n - 1];
}

int frog_jump_k_dist(int n, vector<int>& height, int k) {
    vector<int> dp(n, -1);

    return jump_util(n, height, dp, k);
}

int main() {
    vector<int> height = {10, 5, 20, 0, 15};
    int n = height.size();
    int k = 2;

    cout << "Minimum energy used to climb " << n - 1 << " steps: " << frog_jump_k_dist(n, height, k) << "\n";
    
    return 0;
}