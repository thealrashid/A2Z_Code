#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void mapParents(Node *node, Node *par, unordered_map<Node *, Node *>& parent) {
    if (!node) return;
    parent[node] = par;
    mapParents(node->left, node, parent);
    mapParents(node->right, node, parent); 
}

int minTimeToBurn(Node *root, Node *target) {
    unordered_map<Node *, Node *> parent;

    mapParents(root, nullptr, parent);

    unordered_set<Node *> burned;
    queue<Node *> q;

    q.push(target);
    burned.insert(target);

    int time = 0;

    while (!q.empty()) {
        int n = q.size();
        bool spread = false;

        for (int i = 0; i < n; i++) {
            Node *node = q.front();
            q.pop();

            if (node->left && !burned.count(node->left)) {
                q.push(node->left);
                burned.insert(node->left);
                spread = true;
            }
            if (node->right && !burned.count(node->right)) {
                q.push(node->right);
                burned.insert(node->right);
                spread = true;
            }
            Node *par = parent[node];
            if (par && !burned.count(par)) {
                q.push(par);
                burned.insert(par);
                spread = true;
            }
        }
        if (spread) time++;
    }

    return time;
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
    //root->right->left = new Node(6);
    root->right->right = new Node(7);

    //root->right->right->left = new Node(10);

    Node *target = root->right->right; // Node 7

    cout << minTimeToBurn(root, target) << endl;

    deleteTree(root);

    return 0;
}