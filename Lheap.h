//
// Created by Igor on 30.11.2023.
//

#ifndef KOLEJKI_LHEAP_H
#define KOLEJKI_LHEAP_H
#include "IPQueue.h"


class Lheap : public IPQueue{
    struct node{
        int key;
        node* left;
        node* right;
        int npl;

        node(int key, node* left, node* right, int npl): key(key), left(left), right(right), npl(npl) {}
    };

    node* root = nullptr;

public:
    node *Union(node* tree1, node* tree2);
    int Max() const override {return root->key;}
    int DeleteMax() override;
    void Insert(int key) override;
};


#endif //KOLEJKI_LHEAP_H
