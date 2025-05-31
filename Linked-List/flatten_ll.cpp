#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *child;

    Node() {
        data = 0;
        next = NULL;
        child = NULL;
    }

    Node(int x) {
        data = x;
        next = NULL;
        child = NULL;
    }
};

void display_child(Node *head) {
    Node *curr = head;

    while (curr) {
        cout << curr->data << "->";
        curr = curr->child;
    }

    cout << "NULL" << endl;
}

Node *merge(Node *node1, Node *node2) {
    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (node1 && node2) {
        if (node1->data < node2->data) {
            tail->child = node1;
            tail = node1;
            node1 = node1->child;
        } else {
            tail->child = node2;
            tail = node2;
            node2 = node2->child;
        }

        tail->next = NULL;
    }

    if (node1) {
        tail->child = node1;
    } else {
        tail->child = node2;
    }

    if (dummy->child) {
        dummy->child->next = NULL;
    }

    return dummy->child;
}

Node *flatten_ll(Node *head) {
    if (!head || !head->next) return head;

    Node *mergedhead = flatten_ll(head->next);
    head = merge(head, mergedhead);

    return head;
}

int main() {
    Node *head = new Node(3);
    
    head->next = new Node(2);
    head->next->child = new Node(10);

    head->next->next = new Node(1);
    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(11);
    head->next->next->child->child->child = new Node(12);

    head->next->next->next = new Node(4);
    head->next->next->next->child = new Node(9);

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->child = new Node(6);
    head->next->next->next->next->child->child = new Node(8);

    head = flatten_ll(head);

    display_child(head);

    return 0;
}