#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

int widthOfBinaryTree(Node* root) {
    if (!root) return 0;
    
    int max_width = 0;
    queue<pair<Node *, unsigned long long>> q;
    q.push({root, 1});

    while (!q.empty()) {
        int n = q.size();
        unsigned long long left_width, right_width;

        for (int i = 0; i < n; i++) {
            auto [node, width] = q.front();
            q.pop();
            if (i == 0) left_width = width;
            if (i == n - 1) right_width = width;

            if (node->left) q.push({node->left, 2 * width});
            if (node->right) q.push({node->right, 2 * width + 1});
        }

        max_width = max(max_width, (int)(right_width - left_width + 1));
    }

    return max_width;
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

    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << widthOfBinaryTree(root) << endl;

    deleteTree(root);

    return 0;
}