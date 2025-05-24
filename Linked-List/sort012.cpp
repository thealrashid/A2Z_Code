#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    struct Node *next;

    Node() {
        val = 0;
        next = NULL;
    }

    Node(int x) {
        val = x;
        next = NULL;
    }
};

Node *insert_at_end(Node *head, int x) {
    Node *newnode = new Node(x);

    Node *prev = head;

    if (prev == NULL) {
        newnode->next = head;
        head = newnode;
    } else {
        while (prev->next != NULL) {
            prev = prev->next;
        }

        prev->next = newnode;
    }

    return head;
}

void display_linked_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

Node *sort012(Node *head) {
    if (!head) return head;

    Node *curr = head;
    Node *zerohead = NULL, *onehead = NULL, *twohead = NULL;
    Node *zero = NULL, *one = NULL, *two = NULL;

    while (curr) {
        if (curr->val == 0) {
            if (!zerohead) {
                zerohead = curr;
                zero = zerohead;
            } else {
                zero->next = curr;
                zero = curr;
            }
        } else if (curr->val == 1) {
        if (!onehead) {
                onehead = curr;
                one = onehead;
            } else {
                one->next = curr;
                one = curr;
            }
        } else {
            if (!twohead) {
                twohead = curr;
                two = twohead;
            } else {
                two->next = curr;
                two = curr;
            }
        }

        curr = curr->next;
    }

    if (zero) zero->next = onehead ? onehead : twohead;
    if (one) one->next = twohead;
    if (two) two->next = NULL;

    if (zerohead) return zerohead;
    if (onehead) return onehead;
    return twohead;
}

int main() {
    Node *head = NULL;

    head = insert_at_end(head, 1);
    head = insert_at_end(head, 0);
    head = insert_at_end(head, 0);
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 1);
    head = insert_at_end(head, 0);

    display_linked_list(head);

    head = sort012(head);

    display_linked_list(head);
    

    return 0;
}