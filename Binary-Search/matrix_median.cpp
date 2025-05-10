#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int upperbound(vector<int>& arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int count_small_equal(vector<vector<int>>& mat, int x) {
    int count = 0;
    for (int i = 0; i < mat.size(); i++) {
        count += upperbound(mat[i], x);
    }

    return count;
}

int matrix_median(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < row; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][col - 1]);
    }

    int req = (row * col) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int small_equal = count_small_equal(mat, mid);
        if (small_equal <= req) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main() {
    vector<vector<int>> mat =  {{1, 4, 9},
                                {2, 5, 6},
                                {3, 7, 8}};

    cout << matrix_median(mat) << endl;
    return 0;
}