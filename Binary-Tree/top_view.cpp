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

vector<int> top_view(Node *root) {
    if (!root) return {};
    queue<pair<Node *, int>> q;
    map<int, int> topNode;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, col] = q.front();
        q.pop();

        if (topNode.find(col) == topNode.end()) {
            topNode[col] = node->val;
        }

        if (node->left) q.push({node->left, col - 1});
        if (node->right) q.push({node->right, col + 1});
    }

    vector<int> res;
    for (auto &[col, val] : topNode) {
        res.push_back(val);
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

    root->right->right->right = new Node(10);

    vector<int> res = top_view(root);

    for (auto &itr : res) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}