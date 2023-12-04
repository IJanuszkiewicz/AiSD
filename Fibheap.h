//
// Created by igo-j on 02.12.2023.
//

#ifndef KOLEJKI_FIBHEAP_H
#define KOLEJKI_FIBHEAP_H

#include "IPQueue.h"

class Fibheap : IPQueue{
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
    explicit Fibheap(node* p):head(p), max(p){}
    node *FindMax() const;
    static node *FindMax(node* head);
    void Consolidate();
    static node *MergeTrees(node *root1, node *root2);
    node *Extract();
    static void AddToTab(node **tab, node *p);
public:
    Fibheap(): head(nullptr), max(nullptr){}
    static node *Find(int key, node *head);
    node *Find(int key) {return Find(key, head);}
    void IncreaseKey(node *where, int howMuch);

    void Union(Fibheap heap);
    void Insert(int key) override;
    int Max() const override {return max->key;}
    int DeleteMax() override;
};


#endif //KOLEJKI_FIBHEAP_H
