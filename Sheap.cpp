//
// Created by Igor on 30.11.2023.
//

#include "Sheap.h"

Sheap::node *Sheap::Union(Sheap::node *tree1, Sheap::node *tree2) {
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

    phelp = p->right;
    p->right = p->left;
    p->left = phelp;

    return p;
}
int Sheap::DeleteMax() {
    int max = Max();
    node* p;
    p = root;
    root = Union(root->left, root->right);
    delete p;
    return max;
}
void Sheap::Insert(int key) {
    node* p = new node(key, nullptr, nullptr);
    root = Union(root, p);
}
