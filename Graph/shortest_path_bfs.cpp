#include <bits/stdc++.h>

using namespace std;

void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    queue<int> q;

    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    cout << "Distance from start: " << endl;
    for (auto d : dist) cout << d << " ";
    cout << endl;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    cout << "BFS starting from node 0" << endl;
    bfs(0, adj);

    return 0;
}