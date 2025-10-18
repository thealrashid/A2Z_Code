#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

unordered_map<Node *, Node *> parent;

void mapParents(Node *node, Node *par) {
    if (!node) return;
    parent[node] = par;
    mapParents(node->left, node);
    mapParents(node->right, node); 
}

vector<int> distanceK(Node *root, Node *target, int k) {
    mapParents(root, nullptr);

    unordered_set<Node *> visited;
    queue<Node *> q;

    q.push(target);
    visited.insert(target);

    int dist = 0;
    while (!q.empty()) {
        int n = q.size();
        if (dist == k) break;

        for (int i = 0; i < n; i++) {
            Node *node = q.front();
            q.pop();

            if (node->left && !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
            }
            Node *par = parent[node];
            if (par && !visited.count(par)) {
                q.push(par);
                visited.insert(par);
            }
        }
        dist++;
    }

    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
    }

    return res;
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

    root->right->right->left = new Node(10);

    Node *target = root->right; // Node 3
    int k = 1;

    vector<int> res = distanceK(root, target, k);

    for (auto &itr : res) {
        cout << itr << " ";
    }
    cout << endl;

    deleteTree(root);

    return 0;
}