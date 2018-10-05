#include "MPointerGC.h"

template<>
bool MPointerGC<int>::initialized = false;

template<>
int MPointerGC<int>::current_id = 0;

template<>
DoublyLinkedList<int> MPointerGC<int>::ids = DoublyLinkedList<int>();
