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

Node *odd_even_list(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *odd = head, *even = head->next;
    Node *even_first = even, *odd_prev;

    while (odd != NULL && even != NULL) {
        if (odd->next != NULL) {
            odd->next = odd->next->next;
        }

        if (even->next != NULL) {
            even->next = even->next->next;
        }

        odd_prev = odd;
        odd = odd->next;
        even = even->next;
    }

    if (odd == NULL) {
        odd_prev->next = even_first;
    } else {
        odd->next = even_first;
    }

    return head;
}

int main() {
    Node *head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_at_end(&head, 60);
    insert_at_end(&head, 70);
    insert_at_end(&head, 80);
    //insert_at_end(&head, 90);

    display_linked_list(head);

    odd_even_list(head);

    display_linked_list(head);
    

    return 0;
}