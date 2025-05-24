#include <bits/stdc++.h>

using namespace std;

/*
The numbers are already reversed. The sum should also be in reversed order.
*/

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

    void add_two_numbers(LinkedList<T>* l1, LinkedList<T>* l2) {
        if (!l1) {
            head = l2->head;
            return;
        }
        if (!l2) {
            head = l1->head;
            return;
        }

        Node<T> *curr1 = l1->head, *curr2 = l2->head;
        Node<T> *curr = NULL;
        int carry = 0;

        while (curr1 && curr2) {
            int sum = curr1->data + curr2->data + carry;
            int data = sum % 10;
            carry = sum / 10;
            if (!head) {
                head = new Node<T>(data);
                curr = head;
            } else {
                curr->next = new Node<T>(data);
                curr = curr->next;
            }

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while (curr1) {
            int sum = curr1->data + carry;
            int data = sum % 10;
            carry = sum / 10;

            curr->next = new Node<T>(data);
            curr = curr->next;

            curr1 = curr1->next;
        }

        while (curr2) {
            int sum = curr2->data + carry;
            int data = sum % 10;
            carry = sum / 10;
            
            curr->next = new Node<T>(data);
            curr = curr->next;

            curr2 = curr2->next;
        }

        if (carry) {
            curr->next = new Node<T>(carry);
        }

        head;
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
    LinkedList<int> list1, list2, list;

    list1.insert_at_end(2);
    list1.insert_at_end(4);
    list1.insert_at_end(3);

    list1.display_linked_list();

    list2.insert_at_end(5);
    list2.insert_at_end(6);
    list2.insert_at_end(4);

    list2.display_linked_list();

    list.add_two_numbers(&list1, &list2);

    list.display_linked_list();

    return 0;
}