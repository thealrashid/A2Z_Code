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

void next_permutation(vector<int>& arr, int n) {
    int last_peak = -1;

    for (int i = n-1; i > 0; i--) {
        if (arr[i] > arr[i-1]) {
            last_peak = i;
            break;
        }
    }

    printf("Last peak at position: %d\n", last_peak);

    if (last_peak == -1) {
        sort(arr.begin(), arr.end());
        return;
    }

    int prev = last_peak;

    for (int i = last_peak + 1; i < n; i++) {
        if (arr[i] > arr[last_peak - 1] and arr[i] <= arr[prev]) prev = i;
    }

    swap(arr[last_peak - 1], arr[prev]);
    sort(arr.begin() + last_peak, arr.end());
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
    next_permutation(arr, n);
    printf("Next permutation:\n");
    array_print(arr, n);

    return 0;
}