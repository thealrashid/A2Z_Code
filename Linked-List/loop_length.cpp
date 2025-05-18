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

    int loop_length() {
        if (head == NULL || head->next == NULL) {
            return 0;
        }

        Node<T> *slow = head, *fast = head;
        int length = 1;

        while (slow != NULL && fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                fast = fast->next;

                while (fast != slow) {
                    fast = fast->next;
                    length++;
                }

                return length;
            }
        }

        return 0;
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

    return 0;
}