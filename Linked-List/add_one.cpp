#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T val) {
        data = val;
        next = NULL;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T> *head;

public:
    LinkedList() {
        head = NULL;
    }

    void display_linked_list() {
        Node<T> *current = head;

        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    Node<T> *insert_at_beginning(T val) {
        Node<T> *newnode = new Node<T>(val);

        newnode->next = head;
        head = newnode;

        return head;
    }

    Node<T> *insert_at_end(T val) {
        Node<T> *newnode = new Node<T>(val);

        Node<T> *prev = head;

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

    Node<T> *delete_at_beginning() {
        if (head == NULL) {
            cout << "Empty list" << endl;
        }

        Node<T> *temp = head;
        head = head->next;

        delete temp;

        return head;
    }

    Node<T> *delete_at_end() {
        if (head == NULL) {
            cout << "Empty list" << endl;
        }

        Node<T> *prev, *temp = head;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        delete temp;

        return head;
    }

    Node<T> *reverse_ll() {
        if (head == NULL) {
            return head;
        }

        Node<T> *current = head, *prevnode = NULL, *nextnode;

        while (current != NULL) {
            nextnode = current->next;
            current->next = prevnode;
            prevnode = current;
            current = nextnode;
        }
        
        head = prevnode;

        return head;
    }

    Node<T> *reverse_LL_recursive(Node<T> *node) {
        if (node == NULL || node->next == NULL) {
            return head;
        }

        Node<T> *newhead = reverse_LL_recursive(node->next);
        node->next->next = node; // Form new link
        node->next = NULL; // Severe old link

        head = newhead;

        return head;
    }

    Node<T> *add_one() {
        if (!head) return head;

        head = reverse_ll();

        Node<T> *curr = head, *prev;
        int carry = 1;

        while (curr && carry) {
            prev = curr;

            if (curr->data == 9) {
                curr->data = 0;
            } else {
                curr->data += 1;
                carry = 0;
            }

            curr = curr->next;
        }

        if (!curr) {
            prev->next = new Node(1);
        }

        head = reverse_ll();

        return head;
    }

    ~LinkedList() {
        Node<T> *current = head;

        while (current) {
            Node<T> *nextnode = current->next;
            delete current;
            current = nextnode;
        }
    }
};

int main() {
    LinkedList<int> list;

    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(9);
    list.insert_at_end(9);
    list.insert_at_end(8);

    list.display_linked_list();

    list.add_one();

    list.display_linked_list();

    return 0;
}