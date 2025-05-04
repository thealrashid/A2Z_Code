#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gas_with_dist(vector<int> arr, long double dist) {
    int placed = 0;

    for (int i = 0; i < arr.size() - 1; i++) {
        int curr_dist = arr[i+1] - arr[i];
        int can_place = curr_dist / dist;
        
        if (curr_dist == (dist * can_place)) can_place--;

        placed += can_place;
    }

    return placed;
}

long double gas_station(vector<int> arr, int gas) {
    long double left = 0, right = 0;
    long double mid;

    for (int i = 0; i < arr.size() - 1; i++) {
        right = max(right, (long double)(arr[i+1] - arr[i]));
    }
    
    long double diff = 1e-6;
    while (right - left > diff) {
        mid = (left + right) / (2.0);

        int count = gas_with_dist(arr, mid);
        if (count > gas) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return right;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int gas = 1;

    long double dist = gas_station(arr, gas);
    cout << fixed << setprecision(6);
    cout << "Maximum distance: " << dist << endl;
}