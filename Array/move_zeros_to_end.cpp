#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void move_zeros_to_end(vector<int>& arr, int n) {
    if (n == 1) return;

    int i = 0, j = 1;
    while(j < n) {
        if (arr[i] == 0 && arr[j] == 0) {
            j++;
        } else if (arr[i] != 0 && arr[j] == 0) {
            i++; j++;
        } else if (arr[i] == 0 && arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++; j++;
        } else {
            i++; j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    move_zeros_to_end(arr, n);
    cout << "The final array is:" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}