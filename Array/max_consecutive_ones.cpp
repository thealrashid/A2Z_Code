#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max_consecutive_ones(vector<int> arr, int n) {
    if (n == 1) {
        if (arr[0] == 0) return 0;
        else return 1;
    }

    int i = 0, j = 1;
    int count = 0, max_count = -1;
    while (j < n) {
        if(arr[i] == 1 && arr[j] == 1) {
            while (j < n && arr[j] != 0) {
                j++;
            }
            count = j - i;
            max_count = max(count, max_count);
            if (j != n && j != n-1) {
                i = j;
                j++;
            }
        } else if (arr[i] == 0 && arr[j] == 1) {
            count = 1;
            i++; j++;
        } else {
            i++; j++;
        }
    }
    max_count = max(count, max_count);
    return max_count;
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
    cout << "Enter the elements (only 0s and 1s):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Wrong entry. Please enter 0 or 1." << endl;
            return -1;
        }
    }
    int count = max_consecutive_ones(arr, n);
    cout << "Number of maximum consecutive ones: " << count << endl;

    return 0;
}