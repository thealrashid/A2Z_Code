#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};


Node *lowestCommonAncestor(Node *root, Node *p, Node *q) {
    if (!root || root->val == p->val || root->val == q->val) return root;

        Node *left = lowestCommonAncestor(root->left, p, q);
        Node *right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        else if (right == nullptr) return left;
        return root;
}


/*
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    unordered_map<Node*, Node*> parent;  // map of child -> parent
    queue<Node*> qNodes;

    parent[root] = NULL;  // root has no parent
    qNodes.push(root);

    // Step 1: Build the parent map using BFS
    while (!qNodes.empty()) {
        Node* current = qNodes.front();
        qNodes.pop();

        if (current->left) {
            parent[current->left] = current;
            qNodes.push(current->left);
        }
        if (current->right) {
            parent[current->right] = current;
            qNodes.push(current->right);
        }
    }

    // Step 2: Store ancestors of p
    unordered_set<Node*> ancestors;
    while (p) {
        ancestors.insert(p);
        p = parent[p];
    }

    // Step 3: Move upward from q until you find a common ancestor
    while (q) {
        if (ancestors.find(q) != ancestors.end()) {
            return q; // first common node
        }
        q = parent[q];
    }

    return NULL; // should not reach here if p and q are in the tree
}
*/

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

    Node* p = root->left->left;   // Node 4
    Node* q = root->left->right;  // Node 5

    Node* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << lca->val << endl;
    } else {
        cout << "Not found" << endl;
    }

    deleteTree(root);

    return 0;
}