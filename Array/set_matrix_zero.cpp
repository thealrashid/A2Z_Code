#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}

void set_matrix_zero(vector<vector<int>>& mat, int row, int col) {
    int col0 = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;

                if (j != 0) mat[0][j] = 0;
                else col0 = 0;
            } 
        }
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (mat[i][j] != 0) {
                if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            } 
        }
    }

    if (mat[0][0] == 0) {
        for (int j = 0; j < col; j++) mat[0][j] = 0;
    }

    if (col0 = 0) {
        for (int i = 0; i < row; i++) mat[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> mat = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

    int row = mat.size();
    int col = mat[0].size();

    print_matrix(mat, row, col);

    set_matrix_zero(mat, row, col);

    cout << "After setting matrix zero:" << endl;
    print_matrix(mat, row, col);

    return 0;
}