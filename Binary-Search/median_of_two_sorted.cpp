#include <bits/stdc++.h>

using namespace std;

double median(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    if (n1 > n2) return median(arr2, arr1);

    int n = n1 + n2;
    int left_half = (n1 + n2 + 1) / 2;
    int left = 0, right = n1;
    int mid1, mid2;

    while (left <= right) {
        mid1 = (left + right) / 2;
        mid2 = left_half - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1) r1 = arr1[mid1];
        if (mid2 < n2) r2 = arr2[mid2];

        if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return  ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        } else if (l1 > r2) {
            right = mid1 - 1;
        } else {
            left = mid1 + 1;
        }
    }

    return 0;
}

int main() {
    vector<int> arr1 = {1, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};

    cout << "Median of two sorted arrays: " << median(arr1, arr2) << endl;

    return 0;
}