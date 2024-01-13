//
// Created by Igor on 04.12.2023.
//

#ifndef KOLEJKI_AVL_H
#define KOLEJKI_AVL_H


class Avl {
    struct node {
        int key;
        int bl;
        node *left, *right;
    };
    node *root = nullptr;

    static void RR(node *&p);
    static void LL(node *&p);
    static void LR(node *&p);
    static void RL(node *&p);
public:
    Avl() = default;



};


#endif //KOLEJKI_AVL_H
