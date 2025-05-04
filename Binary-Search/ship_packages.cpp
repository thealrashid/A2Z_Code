#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int can_ship(vector<int> arr, int capacity) {
    int days = 0;
    int daily = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= capacity - daily) {
            daily += arr[i];
        } else {
            daily = arr[i];
            days++;
        }
    }

    days++;

    cout << capacity << " " << days << endl;

    return days;
}

int ship_packages(vector<int> arr, int days) {
    int n = arr.size();

    if (n == 0) return 0;

    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int mid, ans = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (can_ship(arr, mid) <= days) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {5,4,5,2,3,4,5,6};
    int days = 5;
    
    int capacity = ship_packages(arr, days);
    cout << "Least capacity: " << capacity << endl;

    return 0;
}