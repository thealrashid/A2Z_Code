#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getSums(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> sums(n+1);

    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += nums[i];
                count++;
            }
        }

        sums[count].push_back(sum);
    }

    return sums;
}

int minimumDifference(vector<int>& nums) {
    int n = nums.size() / 2;

    vector<int> left(nums.begin(), nums.begin() + n);
    vector<int> right(nums.begin() + n, nums.end());

    vector<vector<int>> leftSums = getSums(left);
    vector<vector<int>> rightSums = getSums(right);

    for (int i = 0; i <= n; i++) {
        sort(rightSums[i].begin(), rightSums[i].end());
    }

    int total = accumulate(nums.begin(), nums.end(), 0);
    int ans = INT_MAX;

    for (int k = 0; k <= n; k++) {
        for (int leftSum : leftSums[k]) {
            int target = total / 2 - leftSum;

            auto& arr = rightSums[n - k];

            auto it = lower_bound(arr.begin(), arr.end(), target);

            if (it != arr.end()) {
                int selectedSum = leftSum + *it;
                ans = min(ans, abs(total - 2 * selectedSum));
            }

            if (it != arr.begin()) {
                --it;
                int selectedSum = leftSum + *it;
                ans = min(ans, abs(total - 2 * selectedSum));
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 9, 7, 3};

    cout << minimumDifference(nums) << "\n";

    return 0;
}