//
// Created by Igor on 30.11.2023.
//

#include <algorithm>
#include "Binheap.h"

Binheap::node *Binheap::MergeTrees(Binheap::node *p1, Binheap::node *p2) {
    node *pHelp;

    if (p1->key < p2->key) {
        pHelp = p1;
        p1 = p2;
        p2 = pHelp;
    }

    if (!p1->child) {
        p1->child = p2;
    } else {
        p1->child->prev->next = p2;
        p2->prev = p1->child->prev;
        p1->child->prev = p2;
    }
    p1->rank++;
    return p1;
}

Binheap::node *Binheap::Union(Binheap::node *root1, Binheap::node *root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    node *p, *p1, *t1, *t2;
    if (root1->rank < root2->rank) {
        p = root1;
        root1 = root2;
        root2 = p;
    }

    if (root1->rank == root2->rank) {
        p = Extract(root1);
        p1 = Extract(root2);
        t1 = Union(root1, root2);
        t2 = MergeTrees(p1, p);
        return Union(t1, t2);
    }
    p = Extract(root2);
    p1 = Union(root1, root2);
    p->next = p1;
    p->prev = p1->prev;
    p1->prev = p;

    return p;

}

Binheap::node *Binheap::Extract(Binheap::node *&p) {
    node *toRet = p;
    if (!p->next) {
        p = nullptr;
        return toRet;
    }

    p = p->next;
    p->prev = toRet->prev;
    toRet->next = nullptr;
    toRet->prev = toRet;
    return toRet;
}

int Binheap::Max() const {
    node *p = root;
    int max = p->key;
    p = p->next;
    while (p) {
        if (p->key > max) max = p->key;
        p = p->next;
    }
    return max;
}

int Binheap::DeleteMax() {
    node *p = root, *pMax = root, *child;

    while (p) {
        if (p->key > pMax->key) pMax = p;
        p = p->next;
    }
    child = pMax->child;
    int max = pMax->key;
    if (pMax->next == nullptr) {
        if (pMax->prev != pMax) {
            root->prev = pMax->prev;
            pMax->prev->next = nullptr;
        } else {
            root = nullptr;
        }
    } else {
        if (pMax == root) {
            root = pMax->next;
            root->prev = pMax->prev;
        } else {
            pMax->next->prev = pMax->prev;
            pMax->prev->next = pMax->next;
        }
    }
    root = Union(root, child);
    delete pMax;
    return max;
}

void Binheap::Insert(int key) {
    node *p = new node(key, 0, nullptr);
    p->prev = p;
    root = Union(root, p);
}

