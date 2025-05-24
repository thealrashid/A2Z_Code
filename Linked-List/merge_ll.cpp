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

Node *insert_at_end(Node **head, int x) {
    Node *newnode = new Node(x);

    Node *prev = *head;

    if (prev == NULL) {
        newnode->next = *head;
        *head = newnode;
    } else {
        while (prev->next != NULL) {
            prev = prev->next;
        }

        prev->next = newnode;
    }

    return *head;
}

void display_linked_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        cout << current->val << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

Node *merge_ll(Node *node1, Node *node2) {
    Node dummy(0);
    Node *tail = &dummy;

    while (node1 and node2) {
        if (node1->val < node2->val) {
            tail->next = node1;
            node1 = node1->next;
        } else {
            tail->next = node2;
            node2 = node2->next;
        }

        tail = tail->next;
    }

    while (node1) {
        tail->next = node1;
        node1 = node1->next;
        tail = tail->next;
    }

    while (node2) {
        tail->next = node2;
        node2 = node2->next;
        tail = tail->next;
    }

    return dummy.next;
}

int main() {
    Node *head1 = NULL;

    insert_at_end(&head1, 1);
    insert_at_end(&head1, 5);
    insert_at_end(&head1, 10);

    Node *head2 = NULL;

    insert_at_end(&head2, 2);
    insert_at_end(&head2, 4);
    insert_at_end(&head2, 6);
    insert_at_end(&head2, 8);

    display_linked_list(head1);
    display_linked_list(head2);

    Node *head = merge_ll(head1, head2);

    display_linked_list(head);
    

    return 0;
}