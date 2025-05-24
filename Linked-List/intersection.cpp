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

Node *intersection(Node *head1, Node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node *curr1 = head1, *curr2 = head2;

    while (curr1 && curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    int count = 0;
    bool a = 0;

    if (curr1) {
        a = 1;
        while (curr1) {
            count++;
            curr1 = curr1->next;
        }
    } else {
        while (curr2) {
            count++;
            curr2 = curr2->next;
        }
    }
    
    curr1 = head1;
    curr2 = head2;

    if (a) {
        for (int i = 0; i < count; i++) {
            curr1 = curr1->next;
        }
    } else {
        for (int i = 0; i < count; i++) {
            curr2 = curr2->next;
        }
    }

    while (curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1;
}

int main() {
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    
    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);

    head1->next->next = head2->next->next->next = new Node(6);

    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(8);

    display_linked_list(head1);

    display_linked_list(head2);
    
    Node *common = intersection(head1, head2);

    if (common) cout << common->val << endl;

    return 0;
}