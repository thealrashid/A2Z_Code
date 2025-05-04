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

int find_rotation(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int mid, ans = INT_MAX, index = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        cout << left << " " << mid << " " << right << " " << index << endl;

        if (arr[left] <= arr[right]) {
            if (arr[left] < ans) {
                index = left;
                ans = arr[left];
            }
            break;
        }

        if (arr[left] <= arr[mid]) {
            if (arr[left] < ans) {
                index = left;
                ans = arr[left];
            }
            left = mid + 1;
        } else {
            if (arr[mid] < arr[right]) {
                index = mid;
                ans = arr[mid];
            }
            right = mid - 1;
        }
    }

    return index;
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

    int rot = find_rotation(arr);
    cout << "The array has been rotated " << rot << " times." << endl;

    return 0;
}