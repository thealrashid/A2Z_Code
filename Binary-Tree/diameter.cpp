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
    delete root;
}

int dfs(Node *node, int& diameter) {
    if (!node) return 0;

    int left = dfs(node->left, diameter);
    int right = dfs(node->right, diameter);

    diameter = max(diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(Node* root) {
    int diameter = 0;

    dfs(root, diameter);

    return diameter;
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

    cout << diameterOfBinaryTree(root) << endl;

    deleteTree(root);

    return 0;
}