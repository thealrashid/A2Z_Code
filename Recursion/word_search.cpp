#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<char>> &board, int row, int col, string word, int index) {
    if (index == word.size()) return true;

    if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0) return false;

    if (board[row][col] != word[index]) return false;

    char temp = board[row][col];
    board[row][col] = '#';

    bool found = dfs(board, row + 1, col, word, index + 1) ||
                 dfs(board, row - 1, col, word, index + 1) ||
                 dfs(board, row, col + 1, word, index + 1) ||
                 dfs(board, row, col - 1, word, index + 1);
    
    board[row][col] = temp;

    return found;
}

bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word = "ABCCED";
    if (exist(board, word)) {
        cout << "Word exists" << endl;
    } else {
        cout << "Word doesn't exist" << endl;
    }
}