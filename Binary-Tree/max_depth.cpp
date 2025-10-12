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

int max_depth(Node *node, int depth) {
    if (!node) return 0;

    int left_depth, right_depth;

    left_depth = max_depth(node->left, depth);
    right_depth = max_depth(node->right, depth);

    return 1 + max(left_depth, right_depth);
}

int maxDepth(Node *root) {
    return max_depth(root, 0);
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

    cout << maxDepth(root) << endl;

    deleteTree(root);

    return 0;
}