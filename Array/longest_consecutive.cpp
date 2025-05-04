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

pair<int, int> longest_consecutive(vector<int>arr, int n) {
    int longest = 0, len = 1;
    int start = 0;
    int ret_start = -1, ret_end = -1;
    bool inside = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1] + 1) {
            len++;
        } else {
            if (len > longest) {
                longest = len;
                ret_start = start;
                ret_end = i - 1;
            }
            start = i;
            len = 1;
        }
    }

    if (len > longest) {
        ret_start = start;
        ret_end = n - 1;
    }

    return {ret_start, ret_end};
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
    pair<int, int> longest = longest_consecutive(arr, n);
    printf("Longest consecutive subarray:\n");
    vector<int> sub_arr(arr.begin() + longest.first, arr.begin() + longest.second + 1);
    array_print(sub_arr, sub_arr.size());

    return 0;
}