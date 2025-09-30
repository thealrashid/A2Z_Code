#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];

        while (!st.empty() && num > nums[st.top()]) {
            res[st.top()] = num;
            st.pop();
        }

        if (i < n) st.push(i);
    }

    return res;
}

int main() {
    vector<int> nums = {1,2,3,4,3};

    vector<int> res = nextGreaterElements(nums);

    for (int itr : res) {
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}