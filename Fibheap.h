//
// Created by igo-j on 02.12.2023.
//

#ifndef KOLEJKI_FIBHEAP_H
#define KOLEJKI_FIBHEAP_H

#include "IPQueue.h"

class Fibheap {
    struct node {
        int key;
        int rank;
        int mark;
        node *prev, *next, *child;

        node(int key, node *prev, node *next = nullptr, node *child = nullptr, int rank = 0,
             int mark = 0) : key(key), prev(prev), next(next), child(child), rank(rank), mark(mark) {}
    };

    node *head = nullptr;
    node *max = nullptr;

public:
    //static void Union(Fibheap &heap1, Fibheap &heap2;);
};


#endif //KOLEJKI_FIBHEAP_H
