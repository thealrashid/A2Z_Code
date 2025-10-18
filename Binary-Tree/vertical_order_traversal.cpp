#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void deleteTree(Node *root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete(root);
}

vector<vector<int>> vertical_order_traversal(Node *root) {
    if (!root) return {};
    queue<tuple<Node *, int, int>> q; // node, row, col
    q.push({root, 0, 0});
    map<int, vector<pair<int, int>>> mp; // key = col, value = list of {row, value}

    while (!q.empty()) {
        auto [node, row, col] = q.front();
        q.pop();
        mp[col].push_back({row, node->val});
        if (node->left) q.push({node->left, row + 1, col - 1});
        if (node->right) q.push({node->right, row + 1, col + 1});
    }

    vector<vector<int>> res;

    for (auto &[col, vec] : mp) {
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> col_vals;
        for (auto &[row, val] : vec) col_vals.push_back(val);
        res.push_back(col_vals);
    }

    return res;
}

int main() {
    Node *root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->right->right->left = new Node(10);

    vector<vector<int>> res = vertical_order_traversal(root);

    for (auto &itr : res) {
        for (auto &i : itr) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}