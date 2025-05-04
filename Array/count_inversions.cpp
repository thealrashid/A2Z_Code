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

int count(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    int inv = 0;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            inv += (mid - i + 1);
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[i++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }

    return inv;
}

int count_inversions(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;

    int inv = 0;
    inv += count_inversions(arr, left, mid);
    inv += count_inversions(arr, mid+1, right);
    inv += count(arr, left, mid, right);

    return inv;
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
    array_print(arr, n);
    int count = count_inversions(arr, 0, n-1);
    cout << "Inversions: " << count << endl;

    return 0;
}