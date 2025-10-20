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

Node *buildTreeHelper(vector<int>& postorder, int& postIndex, 
                    int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = postorder[postIndex--];
    Node *root = new Node(rootVal);

    int inIndex = inMap[rootVal];

    root->right = buildTreeHelper(postorder, postIndex, inIndex + 1, inEnd, inMap);
    root->left = buildTreeHelper(postorder, postIndex, inStart, inIndex - 1, inMap);

    return root;
}
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    int postIndex = postorder.size() - 1;
    return buildTreeHelper(postorder, postIndex, 0, inorder.size() - 1, inMap);
}

int main() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Node *root = buildTree(preorder, inorder);

    deleteTree(root);

    return 0;
}