#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int>> mat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> transpose(vector<vector<int>>& mat, int row, int col) {
    vector<vector<int>> trans(col, vector<int>(row));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    return trans;
}

vector<vector<int>> rotate_matrix(vector<vector<int>>& mat, int row, int col) {
    vector<vector<int>> trans(col, vector<int>(row));

    for (int i = 0; i < row/2; i++) {
        for (int j = 0; j < col; j++) {
            swap(mat[i][j], mat[row-1-i][j]);
        }
    }

    trans = transpose(mat, row, col);

    return trans;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int row = mat.size();
    int col = mat[0].size();

    print_matrix(mat, row, col);

    vector<vector<int>> ans = rotate_matrix(mat, row, col);
    cout << "After rotating clockwise 90 degrees:" << endl;
    print_matrix(ans, row, col);

    return 0;
}