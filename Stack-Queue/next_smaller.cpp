#include <bits/stdc++.h>

using namespace std;

vector<int> nextSmaller(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            res[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }

    return res;
}

int main() {
    vector<int> nums = {4, 8, 5, 2, 25};

    vector<int> res = nextSmaller(nums);

    for (auto &itr : res) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}