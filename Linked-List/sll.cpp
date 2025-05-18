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

    Node<T> *insert_at_position(int pos, T val) {
        if (pos < 1) {
            cout << "Position cannot be less than one" << endl;
            return head;
        }

        if (pos == 1) {
            return insert_at_beginning(val);
        }

        Node<T> *newnode = new Node<T>(val);

        Node<T> *prev = head;
        int count = 1;

        while (prev != NULL && count < pos - 1) {
            count++;
            prev = prev->next;
        }

        if (prev == NULL) {
            cout << "Position out of bound" << endl;
            delete newnode;
            return head; 
        }

        newnode->next = prev->next;
        prev->next = newnode;

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

    // list.delete_at_beginning();
    // list.display_linked_list();

    // list.delete_at_end();
    // list.display_linked_list();

    // list.delete_at_position(2);
    // list.display_linked_list();

    // cout << list.linked_list_length() << endl;

    // list.delete_linked_list();
    // list.display_linked_list();
    // cout << list.linked_list_length() << endl;

    if (list.search_element(81)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not found!" << endl;
    }

    return 0;
}