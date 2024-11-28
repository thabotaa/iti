#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {
private:
    Node* head;
    Node* tail;

    Node* getNodeUsingData(int data) {
        Node* current = head;
        while (current != NULL) {
            if (current->Data == data) {
                return current;
            }
            current = current->Next;
        }
        return NULL;
    }

public:
    LinkedList() {
        head = tail = NULL;
    }

    void add(int data) {
        Node* node = new Node(data);
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->Next = node;
            node->Prev = tail;
            tail = node;
        }
    }

    void display() {
        Node* current = head;
        if (current == NULL) {
            cout << "Linked List is Empty\n";
            return;
        }
        while (current != NULL) {
            cout << current->Data << "\t";
            current = current->Next;
        }
        cout << endl;
    }

    void removeNode(int data) {
        Node* node = getNodeUsingData(data);
        if (node == NULL) {
            cout << "Element Not Found, Can't Remove\n";
            return;
        } else {
            if (node == head) {
                if (node == tail) {
                    tail = head = NULL;
                } else {
                    head = node->Next;
                    head->Prev = NULL;
                }
            } else if (node == tail) {
                tail = node->Prev;
                tail->Next = NULL;
            } else {
                Node* A = node->Prev;
                Node* B = node->Next;
                A->Next = B;
                B->Prev = A;
            }
            delete node;
        }
    }

    int search_using_data(int data) {
        Node* node = getNodeUsingData(data);
        return (node == NULL) ? 0 : 1;
    }

    int get_count() {
        Node* cursor = head;
        int counter = 0;
        while (cursor != NULL) {
            cursor = cursor->Next;
            counter++;
        }
        return counter;
    }

    void bubbleSort() {
        int swapped, i;
        Node* ptr1;
        Node* lptr = NULL;

        /* Checking for empty list */
        if (head == NULL)
            return;

        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->Next != lptr) {
                if (ptr1->Data > ptr1->Next->Data) {
                    swap(ptr1, ptr1->Next);
                    swapped = 1;
                }
                ptr1 = ptr1->Next;
            }
            lptr = ptr1;
        }
        while (swapped);
    }

    void swap(Node* a, Node* b) {
        int temp = a->Data;
        a->Data = b->Data;
        b->Data = temp;
    }
};

#endif // LINKEDLIST_H
