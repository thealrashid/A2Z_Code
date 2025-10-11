#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void preorder_iterative(Node *root) {
    if (!root) return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty()) {
        Node *temp = st.top();
        st.pop();
        cout << temp->val << " ";
        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
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

    preorder_iterative(root);

    deleteTree(root);

    return 0;
}