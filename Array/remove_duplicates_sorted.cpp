#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int remove_duplicates_sorted(vector<int>& arr, int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j+1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int new_size = remove_duplicates_sorted(arr, n);

    cout << "The array without duplicate elements:" << endl;
    for (int i = 0; i < new_size; i++) cout << arr[i] << " ";

    return 0;
}