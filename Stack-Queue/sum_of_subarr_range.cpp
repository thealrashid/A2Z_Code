#include <bits/stdc++.h>

using namespace std;

long long subArrayRanges(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<long long> leftMin(n), rightMin(n), leftMax(n), rightMax(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if(st.empty()) {
            leftMin[i] = i + 1;
        } else {
            leftMin[i] = i - st.top();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if(st.empty()) {
            rightMin[i] = n - i;
        } else {
            rightMin[i] = st.top() - i;
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if(st.empty()) {
            leftMax[i] = i + 1;
        } else {
            leftMax[i] = i - st.top();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if(st.empty()) {
            rightMax[i] = n - i;
        } else {
            rightMax[i] = st.top() - i;
        }
        st.push(i);
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long countMax = leftMax[i] * rightMax[i];
        long long countMin = leftMin[i] * rightMin[i];
        res += (long long)nums[i] * (countMax - countMin);
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};

    long long result = subArrayRanges(nums);

    cout << result << endl;

    return 0;
}