#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {};
};

string serialize(Node* root) {
    if (root == nullptr) return "[]";

    queue<Node *> q;
    q.push(root);
    vector<string> res;

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        if (node) {
            res.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            res.push_back("null");
        }
    }

    while (!res.empty() && res.back() == "null") {
        res.pop_back();
    }

    string str = "[";
    for (int i = 0; i < res.size(); i++) {
        str += res[i];
        if (i < res.size() - 1) str += ",";
    }
    str += "]";

    return str;
}

Node *deserialize(string data) {
    if (data.size() <= 2) return nullptr;

    data = data.substr(1, data.size() - 2);
    stringstream ss(data);
    string item;
    getline(ss, item, ',');
    Node *root = new Node(stoi(item));
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *node = q.front();
        q.pop();

        if (getline(ss, item, ',')) {
            if (item != "null") {
                node->left = new Node(stoi(item));
                q.push(node->left);
            }
        }

        if (getline(ss, item, ',')) {
            if (item != "null") {
                node->right = new Node(stoi(item));
                q.push(node->right);
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

int main() {
    Node *root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    //root->left->left = new Node(4);
    //root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    string str = serialize(root);

    cout << str << endl;

    deleteTree(root);

    Node *node = deserialize(str);

    string data = serialize(node);

    cout << data << endl;

    deleteTree(node);

    return 0;
}