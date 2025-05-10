#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> binary_search_matrix(vector<vector<int>> mat, int k) {
    int row = mat.size();
    int col = mat[0].size();
    int low = 0, high = row - 1;
    int left = 0, right = col - 1;
    int mid1 = -1, mid2 = -1;

    while (low <= high && left <= right) {
        int mid1 = (low + high) / 2;
        int mid2 = (left + right) / 2;

        if (mat[mid1][mid2] == k) {
            return {mid1, mid2};
        } else if (k > mat[mid1][col-1]) {
            low = mid1 + 1;
        } else if (k < mat[mid1][0]) {
            high = mid1 - 1;
        } else {
            while (left <= right) {
                mid2 = (left + right) / 2;

                if (mat[mid1][mid2] < k) {
                    left = mid2 + 1;
                } else {
                    right = mid2 - 1;
                }
            }

            return {mid1, mid2};
        }
    }

    return {mid1, mid2};
}

/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
*/

int main() {
    vector<vector<int>> mat =  {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
    int k = 17;
    vector<int> pos = binary_search_matrix(mat, k);
    if (pos[0] != -1) cout << k << " found at position: " << pos[0] << ", " << pos[1] << endl;
    else cout << k << " not found" << endl;

    return 0;
}