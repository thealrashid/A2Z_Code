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

bool is_balanced(Node *node, int& depth) {
    if (!node) return 1;

    int left_depth = 0, right_depth = 0;

    bool left_balanced = is_balanced(node->left, left_depth);
    bool right_balanced = is_balanced(node->right, right_depth);

    depth = 1 + max(left_depth, right_depth);

    return left_balanced & right_balanced & (abs(left_depth - right_depth) <= 1);
}

bool isBalanced(Node *root) {
    int depth = 0;
    bool balanced = is_balanced(root, depth);
    return balanced;
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

    cout << isBalanced(root) << endl;

    deleteTree(root);

    return 0;
}