#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

vector<vector<int>> zigzagLevelOrder(Node* root) {
    if (root == nullptr) return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> levels;
    bool rev = 0;

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
        
        if (rev) reverse(level.begin(), level.end());
        levels.push_back(level);
        rev = !rev;
    }

    return levels;
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

    vector<vector<int>> zigzag = zigzagLevelOrder(root);

    for (auto level : zigzag) {
        for (auto node : level) {
            cout << node << " ";
        }
    }
    cout << endl;

    deleteTree(root);

    return 0;
}