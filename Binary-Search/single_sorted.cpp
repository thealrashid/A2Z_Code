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

int single_sorted(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int n = arr.size();
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-2] != arr[n-1]) return arr[n-1];

    int left = 1, right = n - 2;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        } else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) && (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
            left = mid + 1;
        } else {
            right = mid + 1;
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
    int ans = single_sorted(arr);
    cout << "Single element: " << ans << endl;

    return 0;
}