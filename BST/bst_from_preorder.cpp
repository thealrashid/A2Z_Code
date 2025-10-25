#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

void construct_subtrees(Node *node, vector<int>& preorder, int start, int end) {
    if (!node) return;

    if (start > end) return;

    if (start == end) {
        if (preorder[start] > node->val) {
            node->right = new Node(preorder[start]);
        } else {
            node->left = new Node(preorder[start]);
        }
        return;
    }

    int index = start;
    while (index <= end) {
        if (preorder[index] > node->val) break;
        index++;
    }

    if (index != start) {
        node->left = new Node(preorder[start]);
        construct_subtrees(node->left, preorder, start + 1, index - 1);
    }
    if (index <= end) {
        node->right = new Node(preorder[index]);
        construct_subtrees(node->right, preorder, index + 1, end);
    }
}
Node* bstFromPreorder(vector<int>& preorder) {
    int start = 1;
    int end = preorder.size() - 1;

    Node *root = new Node(preorder[0]);

    construct_subtrees(root, preorder, start, end);

    return root;
}

/*
TreeNode* build(vector<int>& pre, int start, int end) {
    if (start > end) return nullptr;

    TreeNode* root = new TreeNode(pre[start]);
    int split = start + 1;
    while (split <= end && pre[split] < pre[start]) 
        split++;

    root->left  = build(pre, start + 1, split - 1);
    root->right = build(pre, split, end);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& pre) {
    return build(pre, 0, pre.size() - 1);
}
*/

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

void inorder(Node *root) {
    if (!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node *root = nullptr;
    vector<int> preorder = {8,5,1,7,10,12};

    root = bstFromPreorder(preorder);

    inorder(root);
    cout << endl;

    deleteTree(root);

    return 0;
}