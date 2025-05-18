#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(T val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

template<typename T>
class DoublyLinkedList {
private:
    Node<T> *head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void display_linked_list() {
        Node<T> *current = head;

        while (current != NULL) {
            cout << current->data << " <-> ";
            current = current->next;
        }

        cout << "NULL" << endl;
    }

    Node<T> *insert_at_beginning(T val) {
        Node<T> *newnode = new Node<T>(val);

        newnode->next = head;
        if (head != NULL) head->prev = newnode;
        head = newnode;

        return head;
    }

    Node<T> *delete_at_beginning() {
        if (head == NULL) {
            cout << "Empty list" << endl;
        }

        Node<T> *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;

        return head;
    }

    Node<T> *reverse_dll() {
        if (head == NULL) {
            return head;
        }

        Node<T> *current = head, *temp = NULL;

        while (current != NULL) {
            temp = current->prev; // keep temp prev not next to stay within the list
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }

        return head;
    }

    ~DoublyLinkedList() {
        Node<T> *current = head;

        while (current) {
            Node<T> *nextnode = current->next;
            delete current;
            current = nextnode;
        }
    }
};

int main() {
    DoublyLinkedList<int> list;

    list.insert_at_beginning(50);
    list.insert_at_beginning(40);
    list.insert_at_beginning(30);
    list.insert_at_beginning(20);
    list.insert_at_beginning(10);

    list.display_linked_list();

    list.reverse_dll();
    list.display_linked_list();

    return 0;
}