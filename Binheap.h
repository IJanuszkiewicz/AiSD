//
// Created by Igor on 30.11.2023.
//

#ifndef KOLEJKI_BINHEAP_H
#define KOLEJKI_BINHEAP_H
#include "IPQueue.h"

class Binheap {
    struct node{
        int key;
        int rank;
        node *prev, *next, *child;

        node(int key, int rank, node* prev, node* next = nullptr, node* child = nullptr):
        key(key), rank(rank), prev(prev), next(next), child(child){}
    };

    node* root;

    static node *MergeTree(node *p1, node *p2);
    static node *Extract(Binheap::node *&p)
public:
    static node* Union(node *root1, node *root2);

};


#endif //KOLEJKI_BINHEAP_H
