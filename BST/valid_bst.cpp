#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

bool valid_BST(Node *node, long long min_val, long long max_val) {
    if (!node) return 1;

    if ((long long)node->val < min_val) return 0;
    if ((long long)node->val > max_val) return 0;

    return valid_BST(node->left, min_val, (long long)node->val - 1) && valid_BST(node->right, (long long)node->val + 1, max_val);
}
bool isValidBST(Node* root) {
    if (!root) return 1;

    return valid_BST(root, LLONG_MIN, LLONG_MAX);
}

Node *insert(Node *root, int val) {
    if (!root) {
        root = new Node(val);
        return root;
    }
    Node *node = root;

    while (node) {
        if (val > node->val) {
            if (node->right) node = node->right;
            else {
                node->right = new Node(val);
                break;
            }
        } else {
            if(node->left) node = node->left;
            else {
                node->left = new Node(val);
                break;
            }
        }
    }

    return root;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node *root = nullptr;
    
    root = insert(root, 4);

    root = insert(root, 2);
    root = insert(root, 6);

    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    cout << isValidBST(root) << endl;

    deleteTree(root);

    return 0;
}