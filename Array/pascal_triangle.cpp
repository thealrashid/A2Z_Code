#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascal_triangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

void print_pascal(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = v.size()-i; j > 0; j--) cout << " ";
        for (int k = 0; k < v[i].size(); k++) cout << v[i][k] << " ";
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of rows: ";
    cin >> n;

    vector<vector<int>> v = pascal_triangle(n);

    print_pascal(v);

    return 0;
}