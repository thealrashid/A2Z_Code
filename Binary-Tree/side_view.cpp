#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

vector<int> rightSideView(Node* root) {
    if (root == nullptr) return {};
    queue<Node *> q;
    q.push(root);
    vector<int> right;

    while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            if (i == n - 1) right.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
        
    }

    return right;
}

vector<int> leftSideView(Node* root) {
    if (root == nullptr) return {};
    queue<Node *> q;
    q.push(root);
    vector<int> right;

    while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; i++) {
            Node *temp = q.front();
            if (i == 0) right.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            q.pop();
        }
        
    }

    return right;
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

    root->right->right->right = new Node(10);

    vector<int> left = leftSideView(root);
    vector<int> right = rightSideView(root);

    for (auto &itr : left) cout << itr << " ";
    cout << endl;

    for (auto &itr : right) cout << itr << " ";
    cout << endl;

    deleteTree(root);

    return 0;
}