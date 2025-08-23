#include <bits/stdc++.h>

using namespace std;

void pathFinder(int n, int row, int col, vector<vector<int>> &maze, vector<string> &paths, string current) {
    if (maze[row][col] == 0) return;

    if (row == n - 1 && col == n - 1) {
        paths.push_back(current);
        return;
    }

    if (row > 0) {
        current.push_back('U');
        maze[row][col] = 0;
        pathFinder(n, row - 1, col, maze, paths, current);
        current.pop_back();
        maze[row][col] = 1;
    }

    if (col > 0) {
        current.push_back('L');
        maze[row][col] = 0;
        pathFinder(n, row, col - 1, maze, paths, current);
        current.pop_back();
        maze[row][col] = 1;
    }

    if (row < n - 1) {
        current.push_back('D');
        maze[row][col] = 0;
        pathFinder(n, row + 1, col, maze, paths, current);
        current.pop_back();
        maze[row][col] = 1;
    }

    if (col < n - 1) {
        current.push_back('R');
        maze[row][col] = 0;
        pathFinder(n, row, col + 1, maze, paths, current);
        current.pop_back();
        maze[row][col] = 1;
    }
}

vector<string> ratInAMaze(int n, vector<vector<int>> &maze) {
    vector<string> paths;

    pathFinder(n, 0, 0, maze, paths, "");

    return paths;
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
            {1, 1, 0, 1}, 
            {1, 1, 0, 0},
            {0, 1, 1, 1}};
    
    vector<string> paths = ratInAMaze(n, maze);

    if (paths.empty()) {
        cout << "No valid path exists" << endl;
    } else {
        for (auto &itr : paths) {
            cout << itr << endl;
        }
    }
            
    return 0;
}