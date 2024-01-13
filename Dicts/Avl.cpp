//
// Created by Igor on 04.12.2023.
//

#include "Avl.h"
void Avl::RR(node*& p) {
    // p->bl == -2
    node *x = p->right;
    p->right = x->left;
    x->left = p;
    p->bl = (x->bl == -1) ? 0 : -1;
    x->bl = (x->bl == 0) ? 1 : 0;
    p = x;
}
void Avl::LL(node*& p) {
    // p->bl == 2
    node *x = p->left;
    p->left = x->right;
    x->right = p;
    p->bl = (x->bl == 1) ? 0 : 1;
    x->bl = (x->bl == 0) ? -1 : 0;
    p = x;
}
void Avl::LR(node*& p) { 
}
void Avl::RL(node*& p) {
}
