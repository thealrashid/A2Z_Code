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

Node *remove_nth_from_end(Node **head, int n) {
    if (*head == NULL) return *head;

    Node *last = *head, *prev = *head, *curr = *head;
    int i = 1;
    while (last != NULL and i < n) {
        last = last->next;
        i++;
    }

    while (last->next != NULL) {
        prev = curr;
        curr = curr->next;
        last = last->next;
    }

    if (prev == curr) {
        *head = (*head)->next;
        return *head;
    }

    if (curr != NULL) {
        prev->next = curr->next;
    } else {
        prev->next = NULL;
    }

    return *head;
}

int main() {
    Node *head = NULL;

    insert_at_end(&head, 1);
    //insert_at_end(&head, 2);

    display_linked_list(head);

    remove_nth_from_end(&head, 1);

    display_linked_list(head);
    

    return 0;
}