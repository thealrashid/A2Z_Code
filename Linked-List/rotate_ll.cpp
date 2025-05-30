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

Node *rotate_ll(Node *head, int k) {
    if (!head || !head->next) return head;

    int count = 0;
    Node *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    k = k % count;

    if (k == 0) return head;

    Node *curr = head;
    for (int i = 1; i < count - k; i++) {
        curr = curr->next;
    }

    Node *newhead = curr->next;
    Node *last = newhead;
    while (last->next) {
        last = last->next;
    }

    last->next = head;
    curr->next = NULL;
    head = newhead;

    return head;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    display_linked_list(head);

    head = rotate_ll(head, 3);

    display_linked_list(head);

    return 0;
}