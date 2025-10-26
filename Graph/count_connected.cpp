#include <bits/stdc++.h>

using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsHelper(i, adj, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1};
    adj[1] = {0};
    adj[2] = {3};
    adj[3] = {2};
    // nodes 4 and 5 are isolated

    cout << "Number of connected components: " << countConnectedComponents(adj) << endl;

    return 0;
}