//
// Created by edmobe on 04/10/18.
//

#ifndef MPOINTERSJOINED_TESTLINKEDLIST_H
#define MPOINTERSJOINED_TESTLINKEDLIST_H

#include "MPointer.h"
// A C++ program to sort a linked list using Quicksort

/* a node of the doubly linked list */

class TestLinkedList {
private:
    /* Node of a doubly linked list */
    struct Node {
        MPointer<int>* reference;
        Node* next = NULL; // Pointer tMPointer<int>::New()o next node in DLL
        Node* prev = NULL; // Pointer to previous node in DLL
        Node(MPointer<int>* newRef) {
            reference = newRef;
        }
    };
    Node* head = NULL;
    int len = 0;
public:
    // A utility function to print contents of arr
    void printList() {
        Node* cur = head;
        cout << "[" << " ";
        while (cur) {
            cout << *cur->reference->element << "  ";
            cur = cur->next;
        }
        cout << "]" << endl;
        delete cur;
    }
    /* Function to insert a node at the beginging of the Doubly Linked List */
    void push(MPointer<int>* newRef) {
        Node* newNode = new Node(newRef);     /* allocate node */
        newNode->reference = newRef;

        /* since we are adding at the begining, prev is always NULL */
        newNode->prev = NULL;

        /* link the old list off the new node */
        newNode->next = head;

        /* change prev of head node to new node */
        if (head !=  NULL)  head->prev = newNode ;

        /* move the head to point to the new node */
        head = newNode;
    }
};

#endif //MPOINTERSJOINED_TESTLINKEDLIST_H
