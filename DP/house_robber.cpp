#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    int prev1 = 0, prev2 = 0;

    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> nums = {1,2,3,1};

    cout << rob(nums) << "\n";

    return 0;
}