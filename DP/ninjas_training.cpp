#include<bits/stdc++.h>

using namespace std;

int ninjasTraining(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<int> prev(3, 0), curr(3, 0);

    for (int i = 0; i < 3; i++) prev[i] = mat[0][i];

    for (int i = 1; i < n; i++) {
        curr[0] = mat[i][0] + max(prev[1], prev[2]);
        curr[1] = mat[i][1] + max(prev[0], prev[2]);
        curr[2] = mat[i][2] + max(prev[0], prev[1]);

        prev = curr;
    }

    return max(max(prev[0], prev[1]), prev[2]);
}

int main() {
    vector<vector<int>> mat = {{10, 40, 70},
                               {20, 50, 80},
                               {30, 60, 90}};
    
    cout << ninjasTraining(mat) << "\n";

    return 0;
}