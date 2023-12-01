//
// Created by Igor on 30.11.2023.
//

#include "Lheap.h"

Lheap::node *Lheap::Union(Lheap::node *tree1, Lheap::node *tree2) {
    node *p, *phelp;
    if (!tree1) return tree2;
    if (!tree2) return tree1;

    if (tree1->key > tree2->key) {
        p = tree1;
        p->right = Union(tree1->right, tree2);
    } else {
        p = tree2;
        p->right = Union(tree2->right, tree1);
    }

    if (!p->left || p->right->npl > p->left->npl) {
        phelp = p->right;
        p->right = p->left;
        p->left = phelp;
    }
    if (!p->right) p->npl = 0;
    else
        p->npl = p->right->npl + 1;
    return p;
}
int Lheap::DeleteMax() {
    int max = root->key;
    node *toDel = root;
    root = Union(root->right, root->left);
    delete toDel;
    return max;
}
void Lheap::Insert(int key) {
    node *p;
    p = new node(key, nullptr, nullptr, 0);
    root = Union(root, p);
}
