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

int binary_search(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == k) return mid;
        else if (arr[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
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
    cout << "The array:" << endl;
    array_print(arr, n);
    int k;
    cout << "Enter the number to search: ";
    cin >> k;
    int pos = binary_search(arr, k);
    if (pos != -1) cout << k << " found at position: " << pos << endl;
    else cout << k << " not found" << endl;

    return 0;
}