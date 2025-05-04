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

int min_rotated(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int mid, ans = INT_MAX;

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (arr[left] <= arr[right]) {
            ans = min(ans, arr[left]);
            break;
        }

        if (arr[left] <= arr[mid]) {
            ans = min(ans, arr[left]);
            left = mid + 1;
        } else {
            ans = min(ans, arr[mid]);
            right = mid - 1;
        }
    }

    return arr[ans];
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

    int ans = min_rotated(arr);
    cout << "Min element: " << ans << endl;
    return 0;
}