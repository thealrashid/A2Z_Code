#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    
    if (n == 0) return 0;

    int length = 0;
    int zeroes = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
        if (nums[j] == 0) zeroes++;
        while (zeroes > k) {
            if (nums[i++] == 0) {
                zeroes--;
            }
        }
        length = max(length, j - i + 1);
    }

    return length;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    int length = longestOnes(nums, k);

    cout << length << endl;

    return 0;
}