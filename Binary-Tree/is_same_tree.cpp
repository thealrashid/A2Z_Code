#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

bool isSameTree(Node* p, Node* q) {
    if (!p && !q) return true;               // both empty
    if (!p || !q) return false;              // one empty
    if (p->val != q->val) return false;      // values differ

    // recursively check both sides
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/*
bool isSameTree(Node* p, Node* q) {
    queue<Node*> qp, qq;
    qp.push(p);
    qq.push(q);

    while (!qp.empty() && !qq.empty()) {
        Node* n1 = qp.front(); qp.pop();
        Node* n2 = qq.front(); qq.pop();

        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;

        qp.push(n1->left);
        qp.push(n1->right);
        qq.push(n2->left);
        qq.push(n2->right);
    }

    return qp.empty() && qq.empty();
}
*/

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

    Node *toor = new Node(1);
    
    toor->left = new Node(2);
    toor->right = new Node(3);

    toor->left->left = new Node(4);
    toor->left->right = new Node(5);
    toor->right->left = new Node(6);
    toor->right->right = new Node(7);

    cout << isSameTree(root, toor) << endl;

    deleteTree(root);
    deleteTree(toor);

    return 0;
}