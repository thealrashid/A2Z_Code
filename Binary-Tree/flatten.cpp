#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void flatten(Node *root) {
    Node *curr = root;

    while (curr) {
        if (curr->left) {
            Node *predecessor = curr->left;
            while (predecessor->right) {
                predecessor = predecessor->right;
            }

            predecessor->right = curr->right;

            curr->right = curr->left;
            curr->left = nullptr;
        }

        curr = curr->right;
    }
}

void morrisInorderTraversal(Node *root) {
    Node *curr = root;

    while (curr) {
        if (curr->left == nullptr) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            Node *predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                predecessor->right = curr;
                curr = curr->left;
            } else {
                predecessor->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}

void morrisPreorderTraversal(Node *root) {
    Node *curr = root;

    while (curr) {
        if (curr->left == nullptr) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            Node *predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                cout << curr->val << " ";
                predecessor->right = curr;
                curr = curr->left;
            } else {
                predecessor->right = nullptr;
                curr = curr->right;
            }
        }
    }
    cout << endl;
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

    flatten(root);

    morrisInorderTraversal(root);
    morrisPreorderTraversal(root);

    deleteTree(root);

    return 0;
}