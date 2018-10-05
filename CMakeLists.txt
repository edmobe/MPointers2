cmake_minimum_required(VERSION 3.12)
project(MPointersJoined)

set(CMAKE_CXX_STANDARD 14)

include_directories(MPointer)

add_executable(MPointersJoined
        MPointer/Client.cpp
        MPointer/Client.h
        MPointer/json.hpp
        MPointer/main.cpp
        MPointer/MPointer.cpp
        MPointer/MPointer.h
        MPointer/MPointerGC.cpp
        MPointer/MPointerGC.h MServer/DoublyLinkedList.cpp MServer/DoublyLinkedList.h MPointer/TestLinkedList.h)
