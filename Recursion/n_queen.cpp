#include <bits/stdc++.h>

using namespace std;

void place_queens(int col, vector<string> &board, vector<vector<string>> &result, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
    if (col == n) {
        result.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            // Place queen
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            place_queens(col + 1, board, result, leftrow, upperDiagonal, lowerDiagonal, n);

            // Backtrack
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> n_queen(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));

    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    place_queens(0, board, result, leftrow, upperDiagonal, lowerDiagonal, n);
    
    return result;
}

int main() {
    int n = 4;

    vector<vector<string>> result = n_queen(n);

    for (auto itr : result) {
        for (auto str : itr) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}