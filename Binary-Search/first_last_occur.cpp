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

vector<int> first_last_occur(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    int mid, first = -1, last = -1;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == k) {
            first = mid;
            last = mid;
            int i = mid;
            while (i >= 0) {
                if (arr[i] == k) {
                    first = i;
                    i--;
                } else break;
            }
            i = mid;
            while (i < arr.size()) {
                if (arr[i] == k) {
                    last = i;
                    i++;
                } else break;
            }

            vector<int> v = {first, last};
            return v;
        }
        else if (arr[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    return {-1, -1};
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
    cout << "The array:" << endl;
    array_print(arr, n);
    int k;
    cout << "Enter the number to search: ";
    cin >> k;
    vector<int> v = first_last_occur(arr, k);
    if (v[0] != -1) cout << "First: " << v[0] << " , last: " << v[1] <<endl;
    else cout << k << " not found" << endl;

    return 0;
}