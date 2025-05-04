#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void array_input(vector<int>& arr, int n) {
    for( int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 2) {
            cout << "Invalid input" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

void array_print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void sort_012(vector<int>& arr, int n) {
    int l = 0, m = 0, r = n-1;
    while (m < r) {
        switch(arr[m]) {
            case 0:
            swap(arr[l++], arr[m++]);
            break;
            case 1:
            m++;
            break;
            case 2:
            swap(arr[m], arr[r--]);
            break;
            default:
            exit(EXIT_FAILURE);
        }
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
    vector<int> arr(n);
    cout << "Enter elements (only 0s, 1s and 2s):" << endl;
    array_input(arr, n);
    array_print(arr, n);
    cout << "----------------" << endl;
    sort_012(arr, n);
    cout << "Sorted array:" << endl;
    array_print(arr, n);

    return 0;
}