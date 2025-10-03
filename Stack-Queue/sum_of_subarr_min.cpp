#include <bits/stdc++.h>

using namespace std;

int sumSubarrayMins(vector<int> &arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = i + 1;
        } else {
            left[i] = i - st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n - i;
        } else {
            right[i] = st.top() - i;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        sum = (sum + (long long)arr[i] * left[i] * right[i]) % MOD;
    }

    return (int)sum;
}

int main() {
    vector<int> arr = {3,1,2,4};

    int sum = sumSubarrayMins(arr);

    cout << sum << endl;
    return 0;
}