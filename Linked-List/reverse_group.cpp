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

Node *reverse_group(Node *head, int k) {
    if (!head || !head->next) return head;

    /*
    If you don't want to reverse the group that has fewer than k nodes
    
    Node* temp = head;
    int count = 0;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    if (count < k) return head;
    */

    Node* current = head;
    Node* prevnode = NULL;
    Node* nextnode = NULL;
    int i = 0;

    while (current && i < k) {
        nextnode = current->next;
        current->next = prevnode;
        prevnode = current;
        current = nextnode;
        i++;
    }

    if (current) head->next = reverse_group(current, k);

    return prevnode;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    display_linked_list(head);

    head = reverse_group(head, 3);

    display_linked_list(head);

    return 0;
}