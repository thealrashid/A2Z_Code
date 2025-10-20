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

Node *buildTreeHelper(vector<int>& preorder, int& preIndex, 
                      int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    Node *root = new Node(rootVal);

    int inIndex = inMap[rootVal];

    root->left = buildTreeHelper(preorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildTreeHelper(preorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}

Node *buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;
    return buildTreeHelper(preorder, preIndex, 0, inorder.size() - 1, inMap);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Node *root = buildTree(preorder, inorder);

    deleteTree(root);

    return 0;
}