#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int eat(int mid, vector<int> arr, int n) {
    int h = 0;
    for (int i = 0; i < n; i++) {
        h += (arr[i] / mid);
        if (arr[i]%mid != 0) h++;
    }

    return h;
}

int koko(vector<int> arr, int n, int h) {
    int left = -1, right  = arr[0];
    for (int i = 1; i < n; i++) right  = max(arr[i], right);
    int mid, ans;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (eat(mid, arr, n) <= h) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return ans;
}

int main() {
    int n = 5;
    vector<int> arr = {25, 12, 8, 14, 9};
    int h = 5;

    cout << "k: " << koko(arr, n, h) << endl;

    return 0;
}