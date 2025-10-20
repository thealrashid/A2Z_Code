#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

int countNodes(Node* root) {
    if(!root) return 0;

    Node *t1 = root, *t2 = root;
    int left_height = 0, right_height = 0;

    while (t1) { left_height++; t1 = t1->left; }
    while (t2) { right_height++; t2 = t2->right; }

    if (left_height == right_height) return (1 << left_height) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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
    //root->right->right = new Node(7);

    //root->right->right->left = new Node(10);

    Node *target = root->right->right; // Node 7

    cout << countNodes(root) << endl;

    deleteTree(root);

    return 0;
}