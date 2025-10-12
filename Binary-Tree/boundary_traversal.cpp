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

bool isLeaf(Node *node) {
    return !(node->left || node->right);
}

void addLeftBoundary(Node *root, vector<int>& boundary) {
    Node *node = root->left;

    while (node) {
        if (!isLeaf(node)) boundary.push_back(node->val);
        if (node->left) node = node->left;
        else node = node->right;
    }
}

void addLeaves(Node *root, vector<int>& boundary) {
    if (isLeaf(root)) {
        boundary.push_back(root->val);
        return;
    }

    if (root->left) addLeaves(root->left, boundary);
    if (root->right) addLeaves(root->right, boundary);
}

void addRightBoundary(Node *root, vector<int>& boundary) {
    vector<int> tmp;
    Node* curr = root->right;
    while (curr) {
        if (!isLeaf(curr)) tmp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(tmp.begin(), tmp.end());
    for (int x : tmp) boundary.push_back(x);
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> boundary;

    if (!root) return boundary;
    if (!isLeaf(root)) {
        boundary.push_back(root->val);
    }

    addLeftBoundary(root, boundary);
    addLeaves(root, boundary);
    addRightBoundary(root, boundary);

    return boundary;
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

    vector<int> boundary = boundaryTraversal(root);

    for (int node : boundary) {
        cout << node << " ";
    }
    cout << endl;

    deleteTree(root);

    return 0;
}