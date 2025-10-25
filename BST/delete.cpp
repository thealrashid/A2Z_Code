#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
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

Node *deleteNode(Node *root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else {
            Node *successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }

    return root;
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

    inorder(root);
    cout << endl;

    deleteNode(root, 2);

    inorder(root);
    cout << endl;

    deleteTree(root);

    return 0;
}