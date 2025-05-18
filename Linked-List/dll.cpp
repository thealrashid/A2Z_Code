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

    Node<T> *insert_at_end(T val) {
        Node<T> *newnode = new Node<T>(val);

        Node<T> *current = head;

        if (current == NULL) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        } else {
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = newnode;
            newnode->prev = current;
        }

        return head;
    }

    Node<T> *insert_at_position(int pos, T val) {
        if (pos < 1) {
            cout << "Position cannot be less than one" << endl;
            return head;
        }

        if (pos == 1) {
            return insert_at_beginning(val);
        }

        Node<T> *newnode = new Node<T>(val);

        Node<T> *prevnode = head;
        int count = 1;

        while (prevnode != NULL && count < pos - 1) {
            count++;
            prevnode = prevnode->next;
        }

        if (prevnode == NULL) {
            cout << "Position out of bound" << endl;
            delete newnode;
            return head; 
        }

        newnode->next = prevnode->next;
        if (prevnode->next != NULL) {
            prevnode->next->prev = newnode;
        }
        prevnode->next = newnode;
        newnode->prev = prevnode;

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

    Node<T> *delete_at_position(int pos) {
        if (pos < 1) {
            cout << "Position cannot be less than one" << endl;
            return head;
        }

        if (pos == 1) {
            return delete_at_beginning();
        }

        Node<T> *temp = head;
        int count = 1;

        while (temp != NULL && count < pos - 1) {
            count++;
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bound" << endl;
            return head; 
        }

        Node<T> *target = temp->next;
        temp->next = target->next;
        if (target->next != NULL) {
            target->next->prev = temp;
        }
        delete target;

        return head;
    }

    int linked_list_length() {
        Node<T> *current = head;
        int count = 0;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return count;
    }

    bool search_element(T val) {
        if (head == NULL) {
            return false;
        }

        Node<T> *current = head;

        while (current != NULL) {
            if (current->data == val) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    void delete_linked_list() {
        Node<T> *current = head;

        while (current != NULL) {
            Node<T> *nextnode = current->next;
            delete current;
            current = nextnode;
        }

        head = NULL;
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

    Node<int> *head = list.insert_at_beginning(40);
    list.insert_at_beginning(30);
    list.insert_at_beginning(20);
    list.insert_at_beginning(10);

    list.insert_at_end(50);
    list.insert_at_end(60);
    list.insert_at_end(70);

    list.display_linked_list();

    list.insert_at_position(8, 80);
    list.display_linked_list();

    list.delete_at_beginning();
    list.display_linked_list();

    list.delete_at_end();
    list.display_linked_list();

    list.delete_at_position(6);
    list.display_linked_list();

    cout << list.linked_list_length() << endl;

    if (list.search_element(30)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    list.delete_linked_list();
    list.display_linked_list();
    cout << list.linked_list_length() << endl;

    return 0;
}