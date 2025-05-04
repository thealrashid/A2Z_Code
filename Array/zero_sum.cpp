#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void array_input(vector<int>& arr, int n) {
    for( int i = 0; i < n; i++) cin >> arr[i];
}

void array_print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int zero_sum_longest(vector<int> arr) {
    int ans = 0;
    vector<int> pre(arr.size());
    pre[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        pre[i] = arr[i] + pre[i-1];
    }

    unordered_map<int, int> m;

    for (int i = 0; i < pre.size(); i++) {
        if (pre[i] == 0) ans = max(ans, i+1);

        if(m.find(pre[i]) != m.end()) {
            ans = max(ans, i-m[pre[i]]);
        } else {
            m[pre[i]] = i;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter valid size." << endl;
        return -1;
    }
    vector<int> arr(n);
    array_input(arr, n);
    array_print(arr, n);
    int ans = zero_sum_longest(arr);
    cout << "Length of longest zero sum subarray: " << ans << endl;

    return 0;
}