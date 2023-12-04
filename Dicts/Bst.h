//
// Created by igo-j on 03.12.2023.
//

#ifndef KOLEJKI_BST_H
#define KOLEJKI_BST_H
#include "IDict.h"

struct bstNode{
    int key;
    bstNode *next[2] = {nullptr, nullptr};

    bstNode(int key, bstNode* left = nullptr, bstNode* right = nullptr): key(key){
        next[0] = left;
        next[1] = right;
    }
};

class Bst {
    bstNode *root = nullptr;

public:
    bstNode **Search(int key);
    void Insert(int key);
    void Delete(int key);

};


#endif //KOLEJKI_BST_H
