//
// Created by Igor on 30.11.2023.
//

#ifndef KOLEJKI_SHEAP_H
#define KOLEJKI_SHEAP_H
#include "IPQueue.h"

class Sheap : public IPQueue {
    struct node{
        int key;
        node* left;
        node* right;

        node(int key, node* left, node* right): key(key), left(left), right(right) {}
    };

    node* root = nullptr;
public:
    node *Union(node* tree1, node* tree2);
    int Max() const override {return root->key;}
    int DeleteMax() override;
    void Insert(int key) override;
};


#endif //KOLEJKI_SHEAP_H
