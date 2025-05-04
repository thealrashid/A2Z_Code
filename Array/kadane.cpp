#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

void array_input(vector<int>& arr, int n) {
    for( int i = 0; i < n; i++) cin >> arr[i];
}

void array_print(vector<int> arr, int m, int n) {
    for (int i = m; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
}

int largest_product_contiguous_subarray(vector<int> arr, int n) {
    int max_sum_here = 1, max_so_far = INT_MIN;
    int start = 0, end = 0, temp_start = 0;
    for (int i = 0; i < n; i++) {
        max_sum_here *= arr[i];
        if(max_sum_here > max_so_far) {
            max_so_far = max_sum_here;
            start = temp_start;
            end = i;
        }
        if (max_sum_here == 0) {
            max_sum_here = 1;
            temp_start = i+1;
        }
    }

    array_print(arr, start, end);

    return max_so_far;
}

int largest_sum_contiguous_subarray(vector<int> arr, int n) {
    int max_sum_here = 0, max_so_far = INT_MIN;
    int start = 0, end = 0, temp_start = 0;
    for (int i = 0; i < n; i++) {
        max_sum_here += arr[i];
        if(max_sum_here > max_so_far) {
            max_so_far = max_sum_here;
            start = temp_start;
            end = i;
        }
        if (max_sum_here < 0) {
            max_sum_here = 0;
            temp_start = i+1;
        }
    }

    array_print(arr, start, end);

    return max_so_far;
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
    array_print(arr, 0, n-1);
    // int sum = largest_sum_contiguous_subarray(arr, n);
    // cout << "Largest sum of a contiguous subarray: " << sum << endl;

    int prod = largest_product_contiguous_subarray(arr, n);
    if (prod == INT_MIN) prod = 0;
    cout << "Largest product of a contiguous subarray: " << prod << endl;

    return 0;
}