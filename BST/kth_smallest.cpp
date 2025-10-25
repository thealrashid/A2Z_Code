#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

int kthSmallest(Node *root, int k) {
    stack<Node *> st;
    Node *curr = root;
    int count = 0;
    
    while (curr != nullptr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        count++;
        if (count == k) break;
        curr = curr->right;
    }

    return curr->val;
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

    cout << kthSmallest(root, 3) << endl;

    deleteTree(root);

    return 0;
}