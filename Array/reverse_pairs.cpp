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

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
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
}

int count(vector<int> arr, int left, int mid, int right) {
    int j = mid + 1;
    int rev = 0;

    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[i] > 2 * arr[j]) j++;
        rev += (j - (mid + 1));
    }

    return rev;
}

int count_inversions(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;

    int rev = 0;
    rev += count_inversions(arr, left, mid);
    rev += count_inversions(arr, mid+1, right);
    rev += count(arr, left, mid, right);
    merge(arr, left, mid, right);

    return rev;
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