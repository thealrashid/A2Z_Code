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

bool pair_sum(vector<int> arr, int n, int k) {
    unordered_map<int, int> sum;
    for (int i = 0; i < n; i++) {
        if(sum.find(k - arr[i]) != sum.end()) return 1;
        if(sum.find(arr[i]) == sum.end()) sum[arr[i]] = i;
    }
    return 0;
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
    int k;
    cout << "Enter the sum: ";
    cin >> k;
    if(pair_sum(arr, n, k)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}