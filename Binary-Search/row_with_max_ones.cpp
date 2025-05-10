#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int row_with_max_ones(vector<vector<int>> mat) {
    int row = mat.size();
    int col = mat[0].size();

    int i = 0, j = col - 1;
    int ans, index = INT_MAX;

    while (i < row && j >= 0) {
        if (mat[i][j] == 1) {
            if (j < index) {
                ans = i;
                index = j;
            }
            j--;
        } else {
            i++;
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat =  {{0, 1, 1},
                                {1, 1, 1},
                                {0, 0, 0}};
    cout << "The row with max number of ones: " << row_with_max_ones(mat) << endl;
}