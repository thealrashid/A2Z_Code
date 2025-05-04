#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sum_of_results(vector<int> arr, int div) {
    int ans = 0;
    // cout << "div = " << div << endl;

    for (int i = 0; i < arr.size(); i++) {
        ans += ceil((double)arr[i]/div);

        // cout << ans << " ";
    }

    // cout << endl;

    return ans;
}

int smallest_divisor(vector<int> arr, int limit) {
    int n = arr.size();

    if (n == 0) return 0;

    int left = 1, right = *max_element(arr.begin(), arr.end());
    int mid, ans = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (sum_of_results(arr, mid) <= limit) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int limit = 8;
    
    int sd = smallest_divisor(arr, limit);
    cout << "Smallest divisor: " << sd << endl;

    return 0;
}