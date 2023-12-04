//
// Created by igo-j on 02.12.2023.
//

#include "Fibheap.h"
#include <exception>

#define MAX_CONS_TAB_SIZE 100

void Fibheap::Union(Fibheap heap) {
    if (!head) {
        head = heap.head;
        max = heap.max;
        return;
    }
    if (!heap.head) return;

    node *helper;
    helper = heap.head->prev;
    heap.head->prev = head->prev;
    head->prev->next = heap.head;
    head->prev = helper;
    max = max->key > heap.max->key ? max : heap.max;
}

void Fibheap::Insert(int key) {
    node *p = new node(key, nullptr);
    p->prev = p;
    Fibheap f = Fibheap(p);
    Union(f);
}

int Fibheap::DeleteMax() {
    if (!head) {
        throw std::exception();
    }
    int maxVal = max->key;
    node *toDel = max;
    Fibheap children;

    if (toDel == head) {
        head = toDel->next;
        if (head) {
            head->prev = toDel->prev;
        }
    } else if (toDel == head->prev) {
        head->prev = toDel->prev;
        toDel->prev->next = nullptr;
    } else {
        toDel->prev->next = toDel->next;
        toDel->next->prev = toDel->prev;
    }
    max = FindMax();
    children.head = toDel->child;
    children.max = children.FindMax();

    Union(children);
    Consolidate();

    delete toDel;
    return maxVal;
}

Fibheap::node *Fibheap::FindMax() const {
    node *p = head, *pMax = head;
    while (p) {
        if (p->key > pMax->key) pMax = p;
        p = p->next;
    }
    return pMax;
}

Fibheap::node *Fibheap::FindMax(Fibheap::node *head) {
    node *p = head, *pMax = head;
    while (p) {
        if (p->key > pMax->key) pMax = p;
        p = p->next;
    }
    return pMax;
}

Fibheap::node *Fibheap::Extract() {
    if (!head) return nullptr;

    node *toRet = head;
    head = head->next;
    if (head)
        head->prev = toRet->prev;

    toRet->next = nullptr;
    toRet->prev = toRet;
    if (max == toRet) {
        max = FindMax();
    }
    return toRet;
}

Fibheap::node *Fibheap::MergeTrees(Fibheap::node *root1, Fibheap::node *root2) {
    node *pHelp;

    if (root1->key < root2->key) {
        pHelp = root1;
        root1 = root2;
        root2 = pHelp;
    }

    if (!root1->child) {
        root1->child = root2;
    } else {
        root1->child->prev->next = root2;
        root2->prev = root1->child->prev;
        root2->next = nullptr;
        root1->child->prev = root2;
    }
    root1->rank++;
    return root1;
}

void Fibheap::Consolidate() {
    node *tab[MAX_CONS_TAB_SIZE] = {nullptr};
    node *p = head;
    node *next;
    while (p = Extract()) {
        AddToTab(tab, p);
    }
    head = nullptr;
    max = nullptr;
    for (auto &i: tab) {
        Union(Fibheap(i));
    }
}

void Fibheap::AddToTab(Fibheap::node **tab, node *p) {
    if (tab[p->rank]) {
        int index = p->rank;
        AddToTab(tab, MergeTrees(p, tab[p->rank]));
        tab[index] = nullptr;
    } else {
        tab[p->rank] = p;
    }
}

Fibheap::node *Fibheap::Find(int key, node *head) {
    if (head->key == key) return head;
    if (!head->child) return nullptr;

    node *p = head->child, *maybe;
    while (p) {
        maybe = Find(key, p);
        if(maybe) return maybe;
        p = p->next;
    }
    return nullptr;
}

void Fibheap::IncreaseKey(Fibheap::node *where, int howMuch) {
    // TODO: implement
}
