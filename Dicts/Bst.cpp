//
// Created by igo-j on 03.12.2023.
//

#include "Bst.h"
#include <ctime>
#include <random>
bstNode **Bst::Search(int key) {
    bstNode **ptr = &root;
    while(*ptr && (*ptr)->key != key){
        ptr = &((*ptr)->next[key > (*ptr)->key]);
    }
    return ptr;
}

void Bst::Insert(int key) {
    bstNode **p = Search(key);
    if(*p) return;
    *p = new bstNode(key);
}

void Bst::Delete(int key) {
    bstNode **p = Search(key);
    if(!(*p)) return;

    if((*p)->next[0] && (*p)->next[1]){
        srand(time(nullptr));
        int direction = std::rand() % 2;

        bstNode **toSwap = &((*p)->next[direction]);
        while ((*toSwap)->next[1 - direction]){
            toSwap = &((*toSwap)->next[1 - direction]);
        }
        bstNode *toDel = *p;


    } else {
        bstNode *toDel = *p;
        *p = (*p)->next[0] ? (*p)->next[0] : (*p)->next[1];
        delete toDel;
        return;
    }
}
