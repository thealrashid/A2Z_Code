#include <bits/stdc++.h>

using namespace std;

int frog_jump(int n, vector<int>& height) {
    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(
            dp[i - 1] + abs(height[i] - height[i - 1]),
            dp[i - 2] + abs(height[i] - height[i - 2])
        );
    }

    return dp[n - 1];
}

int main() {
    vector<int> height = {7, 5, 1, 2, 6};
    int n = height.size();

    cout << "Minimum energy used to climb " << n - 1 << " steps: " << frog_jump(n, height) << "\n";
    
    return 0;
}