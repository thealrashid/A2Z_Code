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

    Node<T> *reverse_ll(Node<T> *node) {
        if (node == NULL) {
            return node;
        }

        Node<T> *current = node, *prevnode = NULL, *nextnode;

        while (current != NULL) {
            nextnode = current->next;
            current->next = prevnode;
            prevnode = current;
            current = nextnode;
        }
        
        node = prevnode;

        return node;
    }

    bool palindrome_ll() {
        if (head == NULL || head->next == NULL) {
            return 1;
        }

        Node<T> *slow = head, *fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node<T> *newhead = reverse_ll(slow->next);

        Node<T> *forward = head, *backward = newhead;

        while (backward != NULL) {
            if (forward->data != backward->data) {
                reverse_ll(newhead);
                return 0;
            }

            forward = forward->next;
            backward = backward->next;
        }

        reverse_ll(newhead);

        return 1;
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
    list.insert_at_end(1);
    list.insert_at_end(2);
    list.insert_at_end(2);
    list.insert_at_end(1);
    list.insert_at_end(1);

    list.display_linked_list();

    cout << list.palindrome_ll() << endl;

    list.display_linked_list();

    return 0;
}