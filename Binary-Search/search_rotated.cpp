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

int search_rotated(vector<int> arr, int k) {
    int left = 0, right = arr.size() - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        // Edge case for array with repeated elements
        // if (arr[left] == arr[mid] && arr[mid] == arr[right]) {
        //     left = left + 1;
        //     right = right - 1;
        //     continue;
        // }

        if (arr[mid] == k) {
            return mid;
        } else if (arr[left] <= arr[mid]) {
            if (arr[left] <= k && k <= arr[mid]) right = mid - 1;
            else left = mid + 1;
        } else {
            if (arr[mid] <= k && k <= arr[right]) left = mid + 1;
            else right = mid - 1;
        }
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
    int pos = search_rotated(arr, k);
    if (pos != -1) cout << k << " found at position: " << pos << endl;
    else cout << k << " not found" << endl;

    return 0;
}