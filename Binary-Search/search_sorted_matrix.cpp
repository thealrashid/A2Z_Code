#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool search_sorted_matrix(vector<vector<int>> mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        if (mat[row][col] == k) return 1;
        else if (mat[row][col] < k) row++;
        else col--;
    }

    return 0;
}

int main() {
    vector<vector<int>> mat =  {{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}};
    int k = 18;

    bool found = search_sorted_matrix(mat, k);

    if (found) cout << "Found!" << endl;
    else cout << "Not found" << endl;

    return 0;
}