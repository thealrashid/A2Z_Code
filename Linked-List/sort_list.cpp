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

Node *get_mid(Node *node) {
    Node *slow = node, *fast = node, *prev = NULL;
    
    while (fast and fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) prev->next = NULL;

    return slow;
}

Node *merge(Node *node1, Node *node2) {
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

    tail->next = node1 ? node1 : node2;

    return dummy.next;
}

Node *sort_list(Node *head) {
    if (!head || !head->next) return head;

    Node *mid = get_mid(head);

    Node *left = sort_list(head);
    Node *right = sort_list(mid);

    return merge(left, right);
}

int main() {
    Node *head = NULL;

    insert_at_end(&head, 2);
    insert_at_end(&head, 4);
    insert_at_end(&head, 1);
    insert_at_end(&head, 3);

    display_linked_list(head);

    head = sort_list(head);

    display_linked_list(head);
    

    return 0;
}