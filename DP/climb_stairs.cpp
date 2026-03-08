#include <bits/stdc++.h>

using namespace std;

int climb_stair(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;

    cout << "Ways to climb " << n << " steps: " << climb_stair(n) << "\n";
    
    return 0;
}