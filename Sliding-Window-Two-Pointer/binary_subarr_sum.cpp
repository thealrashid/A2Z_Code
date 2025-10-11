#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    if (n == 0) return 0;
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0;
    int count = 0;

    for (int x : nums) {
        sum += x;
        if (prefixCount.find(sum - goal) != prefixCount.end()) {
            count += prefixCount[sum - goal];
        }
        prefixCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;

    int count = numSubarraysWithSum(nums, goal);

    cout << count << endl;

    return 0;
}