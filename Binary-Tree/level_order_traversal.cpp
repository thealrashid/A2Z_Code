#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

vector<vector<int>> levelOrder(Node* root) {
    if (root == nullptr) return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> levels;

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            level.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
        
        levels.push_back(level);
    }

    return levels;
}

void levelOrderTraversal(Node *root) {
    if (!root) return;

    queue<Node *> q;

    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
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

    levelOrderTraversal(root);

    deleteTree(root);

    return 0;
}