#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void all_traversals(Node *root, vector<int>& pre, vector<int>& in, vector<int>& post) {
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        pair<Node *, int> temp = st.top();
        st.pop();

        if (temp.second == 1) {
            pre.push_back(temp.first->val);
            st.push({temp.first, 2});
            if(temp.first->left) {
                st.push({temp.first->left, 1});
            }
        } else if (temp.second == 2) {
            in.push_back(temp.first->val);
            st.push({temp.first, 3});
            if(temp.first->right) {
                st.push({temp.first->right, 1});
            }
        } else {
            post.push_back(temp.first->val);
        }
    }
}

int main() {
    Node *root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> pre, in, post;

    all_traversals(root, pre, in, post);

    deleteTree(root);

    return 0;
}