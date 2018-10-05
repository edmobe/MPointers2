#ifndef MPOINTERS_MPOINTERGC_H
#define MPOINTERS_MPOINTERGC_H

#include "../MServer/DoublyLinkedList.cpp"
#include <chrono>
#include <thread>
#include <atomic>

/*
 * Based on: https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 */
template <class T> class MPointerGC {
public:
    static MPointerGC<T>& getInstance() {
        initialized = true;
        static MPointerGC<T> instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    void addReference(int id, T* reference) {
        ids.add(id, reference);
    }
    void addDuplicate(int id) {
        ids.addDuplicate(id);
    }
    void removeNode(int id) {
        ids.removeNode(ids.getNode(id));
    }
    void removeMPointer(int id) {
        ids.getNode(id)->refCount--;
    }
    void print() {
        cout << "========== GC ==============" << endl;
        ids.print();
        cout << "=============================" << endl;

    }
    void printNodes() {
        ids.printNodes();
    }

    static void update( std::atomic<bool>& program_is_running, unsigned int update_interval_millisecs )
    {
        const auto wait_duration = std::chrono::milliseconds(update_interval_millisecs) ;
        while( initialized ) {
            for (int i = 0; i < ids.getSize(); i++) {
                if(ids.getAtIndex(i)->refCount == 0) {
                    cout << "The GC has freed the value pointed by " <<
                    ids.getAtIndex(i)->id << endl;
                    ids.removeNode(ids.getAtIndex(i));
                }
            }
            std::this_thread::sleep_for(wait_duration) ;
        }
    }

    const DoublyLinkedList<T> &getIds() const;

    static int getId();

    static bool isInitialized() {
        return initialized;
    }

private:
    static DoublyLinkedList<T> ids;
    static int current_id;
    static bool initialized;
    MPointerGC<T>() {}

public:
    MPointerGC<T>(MPointerGC<T> const&) = delete;
    void operator=(MPointerGC<T> const&) = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
};

template<class T>
const DoublyLinkedList<T> &MPointerGC<T>::getIds() const {
    return ids;
}

template<class T>
int MPointerGC<T>::getId() {
    current_id++;
    return current_id;
}

#endif //MPOINTERS_MPOINTERGC_H
