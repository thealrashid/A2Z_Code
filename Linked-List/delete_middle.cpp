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

Node *delete_middle(Node **head) {
    Node *slow = *head, *fast = *head, *prev = *head;

    while (fast != NULL and fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev == slow) {
        *head = NULL;
        return *head;
    }
    
    prev->next = slow->next;

    return *head;
}

int main() {
    Node *head = NULL;

    insert_at_end(&head, 1);
    //insert_at_end(&head, 2);

    display_linked_list(head);

    delete_middle(&head);

    display_linked_list(head);
    

    return 0;
}