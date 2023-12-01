//
// Created by Igor on 30.11.2023.
//

#include "Binheap.h"

Binheap::node *Binheap::MergeTree(Binheap::node *p1, Binheap::node *p2){
    node *pHelp;

    if(p1->key < p2->key){
        pHelp = p1;
        p1 = p2;
        p2 = pHelp;
    }

    if(!p1->child){
        p1->child = p2;
        p2->prev = p2;
        return p1;
    }
    p1->child->prev->next = p2;
    p2->prev = p1->child->prev;
    p1->child->prev = p2;
    p1->rank++;
    return p1;
}
Binheap::node *Binheap::Union(Binheap::node *root1, Binheap::node *root2) {
    // TODO: Implement Union.
}
Binheap::node *Binheap::Extract(Binheap::node *&p) {
    node* toRet = p;
    if(!p->next){
        p = nullptr;
        return toRet;
    }

    p = p->next;
    p->prev = toRet->prev;
    toRet->next = nullptr;
    toRet->prev = toRet;
    return toRet;
}
