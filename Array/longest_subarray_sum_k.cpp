#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longest_subarray_sum_k_positives(vector<int> arr, int n, int k) {
    int sum = 0;
    int i = 0, j = 0;
    int len = 0, len_max = -1;
    while(j < n) {
        sum += arr[j];
        if (sum < k) {
            j++;
            len++;
        } else if (sum == k) {
            len++;
            len_max = max(len, len_max);
            j++;
        } else {
            while(sum > k && i < j) sum -= arr[i++];
            len = j - i + 1;
            j++;
        }
    }
    len_max = max(len, len_max);
    return len_max;
}

int longest_subarray_sum_k(vector<int> arr, int n, int k) {
    unordered_map<int, int> sum_map;
    int max_len = 0;
    int prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_sum == k) max_len = i + 1;
        else if (sum_map.find(prefix_sum - k) != sum_map.end()) max_len = max(max_len, i - sum_map[prefix_sum-k]);

        if (sum_map.find(prefix_sum) == sum_map.end()) sum_map[prefix_sum] = i;
    }
    return max_len;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter a valid size" << endl;
        return -1;
    }
    vector<int> arr(n);
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the sum: ";
    cin >> k;
    //int len = longest_subarray_sum_k_positives(arr, n, k);
    int len = longest_subarray_sum_k(arr, n, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << len << endl;

    return 0;
}