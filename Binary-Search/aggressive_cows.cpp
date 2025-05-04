#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool can_place(vector<int> arr, int dist, int cows) {
    int placed = 1;
    int last_placed = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - arr[last_placed] >= dist) {
            placed++;
            last_placed = i;
        }
        
        if (placed == cows) return 1;
    }

    // cout << dist << " " << placed << endl;

    return 0;
}

int aggressive_cows(vector<int> arr, int cows) {
    int n = arr.size();

    if (n == 0 || n == 1) return 0;

    sort(arr.begin(), arr.end());

    int left = INT_MAX;
    int right = arr[n-1] - arr[0];
    int mid, ans = -1;

    for (int i = 0; i < n-1; i++) {
        if (arr[i+1] - arr[i] < left) left = arr[i+1] - arr[i];
    }

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (can_place(arr, mid, cows)) {
            ans = mid;
            left = mid + 1;
        } else {
            right  = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {0,3,4,7,10,9};
    int cows = 4;
    
    int dist = aggressive_cows(arr, cows);
    cout << "Minimum distance: " << dist << endl;

    return 0;
}