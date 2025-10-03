#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height) {
    stack<int> st;
    int n = height.size();
    vector<int> left(n), right(n);
    int water = 0;

    left[0] = -1;
    st.push(0);
    for (int i = 1; i < n; i++) {
        if (height[i] >= height[st.top()]) {
            left[i] = -1;
            st.push(i);
        } else {
            left[i] = st.top();
        }
    }

    st = stack<int>();

    right[n - 1] = -1;
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        if (height[i] >= height[st.top()]) {
            right[i] = -1;
            st.push(i);
        } else {
            right[i] = st.top();
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if (left[i] != -1 && right[i] != -1) {
            int diff = min(height[left[i]], height[right[i]]) - height[i];
            water += diff;
        }
    }

    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int water = trap(height);

    cout << water << endl;

    return 0;
}