#include <bits/stdc++.h>

using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsHelper(start, adj, visited);
    cout << endl;
}

void dfsIterative(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> visited(n, false);
    stack<int> st;

    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    cout << "BFS starting from node 0" << endl;
    //dfs(0, adj);
    dfsIterative(0, adj);

    return 0;
}