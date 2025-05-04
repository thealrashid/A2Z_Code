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

bool array_check_eq_pos_neg(vector<int> arr, int n) {
    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) neg++;
        else pos++;
    }
    return (pos == neg);
}

void array_right_rotate(vector<int>& arr, int start, int end) {
    int temp = arr[end];
    for (int i = end; i > start; i--) {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void array_alternate_pos_neg(vector<int>& arr, int n) {
    int pos = 0, neg = 1;
    while (pos < n and neg < n) {
        if (arr[pos] < 0) {
            int temp = pos;
            while (temp < n and arr[temp] < 0) temp++;
            if (temp < n) array_right_rotate(arr, pos, temp);
        }

        if (arr[neg] >= 0) {
            int temp = neg;
            while (temp < n and arr[temp] >= 0) temp++;
            if (temp < n) array_right_rotate(arr, neg, temp);
        }

        pos += 2;
        neg += 2;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter valid size." << endl;
        return -1;
    }
    if(n%2 != 0) {
        cout << "Array size must be even number" << endl;
        return -1;
    }
    vector<int> arr(n);
    array_input(arr, n);
    array_print(arr, n);
    if(!array_check_eq_pos_neg(arr, n)) {
        cout << "Enter equal number of positive and negative numbers" << endl;
        return -1;
    }
    array_alternate_pos_neg(arr, n);
    array_print(arr, n);

    return 0;
}