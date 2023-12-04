cmake_minimum_required(VERSION 3.26)
project(kolejki)

set(CMAKE_CXX_STANDARD 17)

add_executable(kolejki main.cpp
        heap.h
        heap.cpp
        beap.h
        beap.cpp
        Lheap.h
        Lheap.cpp
        Sheap.h
        Sheap.cpp
        Binheap.h
        Binheap.cpp
        Fibheap.cpp
        Fibheap.h
        Dicts/IDict.h
        Dicts/IDict.h
        Dicts/Bst.cpp
        Dicts/Bst.h
        TwoThreeTree.cpp
        TwoThreeTree.h)
