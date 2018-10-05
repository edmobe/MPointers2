//
// Created by edmobe on 04/10/18.
//

#ifndef MPOINTERSJOINED_DOUBLYLINKEDLIST_H
#define MPOINTERSJOINED_DOUBLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <class T> class DoublyLinkedList {
private:
    /* Node of a doubly linked list */
    struct Node {
        int id;
        int refCount;
        T* reference;
        Node* next; // Pointer to next node in DLL
        Node* prev; // Pointer to previous node in DLL
        Node(int newId, T* newReference) {
            id = newId;
            reference = newReference;
            refCount = 1;
        }
    };
    Node* head = NULL;
    Node* tail = NULL;
    int len = 0;
public:
    void print() {
        Node* temp = head;
        while(temp) {
            cout << "(ID: " << temp->id << " (reference count: " <<
            temp->refCount << ") pointing to: " << temp->reference << endl;
            temp = temp->next;
        }
    }
    void printNodes() {
        Node* temp = head;
        while(temp) {
            cout << "[ID: " << temp->id << ", data: " <<
                 *temp->reference<<  "] ->" << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void add(int newId, T* newReference) {
        if(head == NULL && tail == NULL) { //case 1//
            head = new Node(newId, newReference);
            tail = head;
        }
        else {
            Node* cur = head;
            while(cur) {
                cur = cur->next;
            }
            if(cur == head) {
                cur->prev = new Node(newId, newReference);
                cur->prev->next = head;
                head = cur->prev;
            }
            else {
                tail->next = new Node(newId, newReference);
                tail->next->prev = tail;
                tail = tail->next;
            }
        }
    }
    Node* getNode(int id) {
        Node* cur = head;
        while (cur) {
            if (cur->id == id) {
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
    Node* getAtIndex(int index) {
        if (index > len) {
            return NULL;
        }
        Node* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur;
    }

    void removeNode(Node* ref)
    {
        /* base case */
        if(head == NULL || tail == NULL)
            return;

        /* If node to be deleted is head node */
        if(head == ref)
            head = ref->next;

        /* Change next only if node to be deleted is NOT the last node */
        if(ref->next != NULL)
            ref->next->prev = ref->prev;

        /* Change prev only if node to be deleted is NOT the first node */
        if(ref->prev != NULL)
            ref->prev->next = ref->next;

        /* Finally, free the memory occupied by del*/
        free(ref);
        return;
    }

    void addDuplicate(int id) {
        getNode(id)->refCount++;
    }
};


#endif //MPOINTERSJOINED_DOUBLYLINKEDLIST_H
