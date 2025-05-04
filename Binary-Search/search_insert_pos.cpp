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

int search_insert_pos(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int ans = arr.size(), mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] < k) left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }

    return mid;
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
    cout << "Sorted array:" << endl;
    array_print(arr, n);
    int k;
    cout << "Enter the number to insert: ";
    cin >> k;
    int pos = search_insert_pos(arr, k);
    cout << k << " should be inserted at position: " << pos << endl;

    return 0;
}