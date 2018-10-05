//
// Created by maria on 15/09/18.
//
#include <typeinfo>
#include "json.hpp"
#include "TestLinkedList.h"
#include "Client.h"

int main(int argc, char *argv[]) {
    // ==================== INITIALIZE THREAD ====================================
    MPointerGC<int>& instance = MPointerGC<int>::getInstance();

    std::atomic<bool> running { true } ;
    const unsigned int update_interval = 5000 ; // update after every second
    std::thread update_thread(MPointerGC<int>::update, std::ref(running), update_interval );
    // ============================================================================

    /*
    Client* cliente = new Client();
    */

    MPointer<int> mPtr = MPointer<int>::New();
    //mPtr.print();
    //mPtr = 11111;
    //mPtr.print();
    mPtr = 11112;
    mPtr.print();
    //*myPtr = 5;
    //int valor = &myPtr;
    //cout << "Valor: " << valor << endl;

    MPointer<int> mPtr2 = MPointer<int>::New();
    mPtr2 = 2222;
    mPtr2.print();
    MPointer<int> mPtr3 = MPointer<int>::New();
    mPtr3 = 333;
    mPtr3.print();
    MPointer<int> mPtr4 = MPointer<int>::New();
    mPtr4 = mPtr;
    mPtr4.print();

    instance.print();
    instance.printNodes();

    cout << "===========================" << endl;

    int command = -1;
    TestLinkedList list;
    list.push(mPtr.get());
    list.push(mPtr2.get());
    list.push(mPtr3.get());
    list.push(mPtr4.get());
    list.quickSort();
    list.bubbleSort();
    list.insertionSort();

    while (command != 0) {
        cout << "=========== TEST ==============" << endl;
        cout << "Enter 1 to delete mPtr" << endl;
        cout << "Enter 2 to delete mPtr2" << endl;
        cout << "Enter 3 to delete mPtr3" << endl;
        cout << "Enter 4 to delete mPtr4" << endl;
        cout << "Enter 5 to print the GC" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "===============================" << endl;
        cin >> command;
        if (command == 1) {
            mPtr.~MPointer<int>();
        } else if (command == 2) {
            mPtr2.~MPointer<int>();
        } else if (command == 3) {
            mPtr3.~MPointer<int>();
        } else if (command == 4) {
            mPtr4.~MPointer<int>();
        } else if (command == 5) {
            instance.print();
        }
    }

    /*
     * MPOINTER GC UTILITY EXAMPLE
     */

    //Testing testing;
    //testing.withoutGC();

    /*
    int command;
    while(command != 0){
        cout << "Press 1 to create a memory leak." << endl;
        cout << "Press 2 to not create a memory leak" << endl;
        cout << "Press 3 to use MPointers and GC" << endl;
        cout << "Press 0 to exit" << endl;
        cin >> command;
        if (command == 1) {
            for (int i = 0; i < 10000; i++) {
                MPointer<int>* mPointer = new MPointer<int>();
            }
        } else if (command == 2) {
            for (int i = 0; i < 10000; i++) {
                MPointer<int>* mPointer = new MPointer<int>();
                delete(mPointer);
            }
        } else if (command == 3) {
            for (int i = 0; i < 10000; i++) {
                MPointer<int> mPointer = MPointer<int>::New();
            }
        }
    }
    */

    // ================== THREAD END =========================
    // exit gracefully
    running = false ;
    update_thread.join() ;
    // =======================================================
}