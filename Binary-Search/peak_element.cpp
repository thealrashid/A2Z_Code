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

int peak_element(vector<int> arr) {
    int n = arr.size();
    int mid;

    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return n-1;

    int left = 1, right = n - 2;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        else if (arr[mid] < arr[mid - 1]) right = mid - 1;
        else left = mid + 1;
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
    
    int peak = peak_element(arr);
    if (peak != -1) cout << "Peak element: " << arr[peak] << endl;
    else cout << "No peak element" << endl;

    return 0;
}