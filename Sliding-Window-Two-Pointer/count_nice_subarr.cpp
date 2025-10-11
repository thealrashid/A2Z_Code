#include <bits/stdc++.h>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return 0;
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0;
    int count = 0;

    for (int x : nums) {
        if (x % 2 != 0) sum ++;
        if (prefixCount.find(sum - k) != prefixCount.end()) {
            count += prefixCount[sum - k];
        }
        prefixCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    int count = numberOfSubarrays(nums, k);
    cout << count << endl;

    return 0;
}