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
    Node* get(int index) {
        if (index <= len) {
            Node* cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur;
        }
        return NULL;
    }
    /* Function to insert a node at the beginging of the Doubly Linked List */
    void push(MPointer<int>* newRef) {
        Node *newNode = new Node(newRef);     /* allocate node */
        newNode->reference = newRef;

        /* since we are adding at the begining, prev is always NULL */
        newNode->prev = NULL;

        /* link the old list off the new node */
        newNode->next = head;

        /* change prev of head node to new node */
        if (head != NULL) head->prev = newNode;

        /* move the head to point to the new node */
        head = newNode;
        len++;
    }
    void quickSort() {
        int tempArray [len];
        for (int i = 0; i < len; i++) {
            tempArray[i] = *get(i)->reference->element;
        }
        // ------------ QUICKSORT --------------------
        int n = sizeof(tempArray)/sizeof(tempArray[0]);
        _quickSort(tempArray, 0, n - 1);
        printArray("Quicksort", tempArray, n);
    }
    void bubbleSort() {
        int tempArray [len];
        for (int i = 0; i < len; i++) {
            tempArray[i] = *get(i)->reference->element;
        }
        // ------------ QUICKSORT --------------------
        int n = sizeof(tempArray)/sizeof(tempArray[0]);
        _bubbleSort(tempArray, n - 1);
        printArray("BubbleSort", tempArray, n);
    }
    void insertionSort() {
        int tempArray [len];
        for (int i = 0; i < len; i++) {
            tempArray[i] = *get(i)->reference->element;
        }
        // ------------ QUICKSORT --------------------
        int n = sizeof(tempArray)/sizeof(tempArray[0]);
        _insertionSort(tempArray, n - 1);
        printArray("InsertionSort", tempArray, n);
    }

private:
    void printArray (string method, int arr[], int size) {
        int i;
        cout << method << ": [ ";
        for (i=0; i < size; i++)
            printf("%d ", arr[i]);
        cout << "]" << endl;
    }
    // A utility function to swap two elements
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high- 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (arr[j] <= pivot)
            {
                i++;    // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low  --> Starting index,
    high  --> Ending index */
    void _quickSort(int arr[], int low, int high) {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = partition(arr, low, high);

            // Separately sort elements before
            // partition and after partition
            _quickSort(arr, low, pi - 1);
            _quickSort(arr, pi + 1, high);
        }
    }
    // A function to implement bubble sort
    void _bubbleSort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n-1; i++)

            // Last i elements are already in place
            for (j = 0; j < n-i-1; j++)
                if (arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
    }
    /* Function to sort an array using insertion sort*/
    void _insertionSort(int arr[], int n)
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i-1;

            /* Move elements of arr[0..i-1], that are
               greater than key, to one position ahead
               of their current position */
            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }
    }
};

#endif //MPOINTERSJOINED_TESTLINKEDLIST_H
