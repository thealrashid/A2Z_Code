#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find_max_row_index(vector<vector<int>>& matrix, int row, int col) {
    int max_row_index = -1;
    int max_row = INT_MIN;
    for (int i = 0; i < row; i++) {
        if (matrix[i][col] > max_row) {
            max_row = matrix[i][col];
            max_row_index = i;
        }
    }

    return max_row_index;
}

vector<int> peak_element_matrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        int max_row_index = find_max_row_index(matrix, n, mid);

        int left = mid > 0 ? matrix[max_row_index][mid - 1] : -1;
        int right = mid < m - 1 ? matrix[max_row_index][mid + 1] : -1;

        if (matrix[max_row_index][mid] > left && matrix[max_row_index][mid] > right) {
            return {max_row_index, mid};
        } else if (matrix[max_row_index][mid] < left) high = mid - 1;
        else low = mid + 1;
    }

    return {-1, -1};
}


int main() {
    vector<vector<int>> mat =  {{1, 4},
                                {3, 2}};

    vector<int> pos = peak_element_matrix(mat);
    if (pos[0] != -1) cout << "Peak element found at position: " << pos[0] << ", " << pos[1] << endl;
    else cout << "Not found" << endl;

    return 0;
}