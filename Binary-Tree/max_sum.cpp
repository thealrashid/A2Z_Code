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

int dfs(Node *node, int& sum) {
    if (!node) return 0;

    int left = max(0, dfs(node->left, sum));
    int right = max(0, dfs(node->right, sum));

    sum = max(sum, node->val + left + right);

    return node->val + max(left, right);
}
int maxPathSum(Node* root) {
    int sum = INT_MIN;

    dfs(root, sum);

    return sum;
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

    cout << maxPathSum(root) << endl;

    deleteTree(root);

    return 0;
}