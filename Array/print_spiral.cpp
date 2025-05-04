#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}

void print_spiral(vector<vector<int>> mat, int row, int col) {
    int up = 0;
    int down = row - 1;
    int left = 0;
    int right = col - 1;

    while (up <= down and left <= right) {
        for (int i = left; i <= right; i++) {
            cout << mat[up][i] << " ";
        }
        up++;

        for (int j = up; j <= down; j++) {
            cout << mat[j][right] << " ";
        }
        right--;

        for (int i = right; i >= left; i--) {
            cout << mat[down][i] << " ";
        }
        down--;

        for (int j = down; j >= up; j--) {
            cout << mat[j][left] << " ";
        }
        left++;
    }

    cout << endl;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4}, 
                                {5, 6, 7, 8}, 
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};

    int row = mat.size();
    int col = mat[0].size();

    print_spiral(mat, row, col);

    return 0;
}