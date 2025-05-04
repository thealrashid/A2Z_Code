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

int subarray_sum(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int count = 0;
    int curr_sum = 0;

    unordered_map<int, int> prefix_sum;

    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];

        if (curr_sum == k) count++;

        if (prefix_sum.find(curr_sum-k) != prefix_sum.end()) count += prefix_sum[curr_sum-k];
        
        prefix_sum[curr_sum]++;
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter valid size." << endl;
        return -1;
    }
    vector<int> arr(n);
    array_input(arr, n);
    array_print(arr, n);

    cout << "Enter the sum: ";
    cin >> k;
    int count = subarray_sum(arr, k);
    cout << "Count: " << count << endl;

    return 0;
}