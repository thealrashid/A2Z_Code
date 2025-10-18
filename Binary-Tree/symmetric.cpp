#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

bool isSymmetric(Node* root) {
    if (!root) return true;
    queue<Node *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        Node *t1 = q.front();
        q.pop();
        Node *t2 = q.front();
        q.pop();

        if (!t1 && !t2) continue;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;

        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
    }

    return true;
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
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    //root->right->right->right = new Node(10);

    cout << isSymmetric(root) << endl;

    deleteTree(root);

    return 0;
}