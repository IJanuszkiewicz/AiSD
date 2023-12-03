//
// Created by Igor on 30.11.2023.
//

#ifndef KOLEJKI_BINHEAP_H
#define KOLEJKI_BINHEAP_H

#include "IPQueue.h"

class Binheap : public IPQueue {
    struct node {
        int key;
        int rank;
        node *prev, *next, *child;

        node(int key, int rank, node *prev, node *next = nullptr, node *child = nullptr) :
                key(key), rank(rank), prev(prev), next(next), child(child) {}
    };

    node *root = nullptr;

    static node *MergeTrees(Binheap::node *p1, Binheap::node *p2);

    static node *Extract(Binheap::node *&p);

public:

    static node *Union(node *root1, node *root2);

    [[nodiscard]] int Max() const override;

    int DeleteMax() override;

    void Insert(int key) override;
};


#endif //KOLEJKI_BINHEAP_H
