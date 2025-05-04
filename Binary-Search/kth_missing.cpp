#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int kth_missing(vector<int> arr, int k) {
    int n = arr.size();

    if (n == 0) return 0;

    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        int missing = arr[mid] - (mid + 1);

        if (missing < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return k + right + 1; // arr[right] + k - (arr[right] - (right+1));
}

int main() {
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    
    int kth = kth_missing(arr, k);
    cout << "Kth missing number: " << kth << endl;

    return 0;
}