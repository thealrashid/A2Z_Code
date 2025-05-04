#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rotate_array(vector<int>& arr, int m, int n) {
    for (int i = m, j = n; i < j; i++, j--) swap(arr[i], arr[j]);
}

void rotate_array_by_k(vector<int>& arr, int n, int dir, int k) {
    if (dir != 0) {
        rotate_array(arr, 0, n-1-k);
        rotate_array(arr, n-k, n-1);
        rotate_array(arr, 0, n-1);
    } else {
        rotate_array(arr, 0, k-1);
        rotate_array(arr, k, n-1);
        rotate_array(arr, 0, n-1);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int dir;
    cout << "Enter 1 to rotate right, 0 to rotate left: ";
    cin >> dir;
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;
    rotate_array_by_k(arr, n, dir, k%n);
    cout << "The rotated array:" << endl;
    for (int i= 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}