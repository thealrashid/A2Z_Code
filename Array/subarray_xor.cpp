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

int subarray_xor(vector<int>& arr, int k) {
    int i = 0, j = 0;
    int count = 0;
    int curr_xor = 0;

    unordered_map<int, int> prefix_xor;

    for (int i = 0; i < arr.size(); i++) {
        curr_xor ^= arr[i];

        if (curr_xor == k) count++;

        if (prefix_xor.find(curr_xor^k) != prefix_xor.end()) count += prefix_xor[curr_xor^k];
        
        prefix_xor[curr_xor]++;
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

    cout << "Enter the xor: ";
    cin >> k;
    int count = subarray_xor(arr, k);
    cout << "Count: " << count << endl;

    return 0;
}