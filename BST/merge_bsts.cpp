#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

Node *canMerge(vector<Node *>& trees) {
    unordered_map<int, int> mp; // node->val => degree

    for (auto tree : trees) {
        
    }
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

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node *root1 = nullptr;
    root1 = insert(root1, 2);
    root1 = insert(root1, 1);

    Node *root2 = nullptr;
    root2 = insert(root2, 3);
    root2 = insert(root2, 2);
    root2 = insert(root2, 5);

    Node *root3 = nullptr;
    root3 = insert(root3, 5);
    root3 = insert(root3, 4);

    vector<Node *> trees = {root1, root2, root3};

    Node *root = canMerge(trees);

    deleteTree(root);

    return 0;
}