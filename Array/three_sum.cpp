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

vector<vector<int>> three_sum(vector<int> arr) {
    int n = arr.size();
    int i, j, k;
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (i = 0; i < n-2; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;

        j = i+1;
        k = n-1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0) {
                ans.push_back({arr[i], arr[j], arr[k]});

                while (j < k && arr[j] == arr[j + 1]) j++;
                while (j < k && arr[k] == arr[k - 1]) k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    return ans;
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

    return 0;
}