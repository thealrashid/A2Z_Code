#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void postorder_iterative(Node *root) {
    if (!root) return;

    stack<Node *> st;
    Node *curr = root;
    Node *lastvisited = nullptr;

    while (curr != nullptr || !st.empty()) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node *peekNode = st.top();

            if (peekNode->right && lastvisited != peekNode->right) {
                curr = peekNode->right;
            } else {
                cout << peekNode->val << " ";
                lastvisited = peekNode;
                st.pop();
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

    postorder_iterative(root);

    deleteTree(root);

    return 0;
}