#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_possible(vector<int> arr, int n, int mid, int m, int k) {
    int ans = 0;
    int m1 = m, k1 = k;

    for (int i = 0; i < n; i++) {
        if (mid >= arr[i]) k1--;
        else {
            k1 = k;
            continue;
        } 

        if (m1 == 0) m1 = m;
        if (k1 == 0) {
            ans++;
            k1 = k;
            m1--;
        }
    }

    return (ans >= m);
}

int min_days(vector<int> arr, int n, int m, int k) {
    int left = -1, right = arr[0];
    for (int i = 1; i < n; i++) right  = max(right, arr[i]);

    int mid, ans = -1;

    while (left <= right) {
        mid  = (left + right) / 2;

        if (is_possible(arr, n, mid, m, k)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return ans;
}

int main() {
    int n = 5;
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 2;

    cout << "Minimum number of days: " << min_days(arr, n, m, k) << endl; 
}