#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

bool find_path(Node *node, int target, vector<int>& path) {
    if (!node) return 0;

    path.push_back(node->val);

    if (node->val == target) return 1;

    if (find_path(node->left, target, path) || find_path(node->right, target, path)) {
        return 1;
    }

    path.pop_back();
    return 0;
}

vector<int> rootToNodePath(Node *root, int target) {
    if (!root) return {};

    vector<int> path;

    find_path(root, target, path);

    return path;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
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

    vector<int> path = rootToNodePath(root, 10);

    for (auto &itr : path) {
        cout << itr << " ";
    }
    cout << endl;

    deleteTree(root);

    return 0;
}