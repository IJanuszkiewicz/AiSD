//
// Created by igo-j on 03.12.2023.
//

#include "Bst.h"
#include <ctime>
#include <random>

bstNode **Bst::Search(int key) {
    bstNode **ptr = &root;
    while (*ptr && (*ptr)->key != key) {
        ptr = &((*ptr)->next[key > (*ptr)->key]);
    }
    return ptr;
}

void Bst::Insert(int key) {
    bstNode **p = Search(key);
    if (*p) return;
    *p = new bstNode(key);
}

void Bst::Delete(int key) {
    bstNode **p = Search(key);
    if (!(*p)) return;
    bstNode *toDel = *p;

    if (!(*p)->next[0] || !(*p)->next[1]) {
        *p = (*p)->next[0] ? (*p)->next[0] : (*p)->next[1];
    } else {
        srand(time(nullptr));
        int direction = std::rand() % 2;

        if (!(toDel->next[direction]->next[1 - direction])) {
            *p = toDel->next[direction];
            (*p)->next[1 - direction] = toDel->next[1 - direction];
        } else {
            bstNode **toSwap = &(toDel->next[direction]->next[1 - direction]);
            while ((*toSwap)->next[1 - direction])
                toSwap = &((*toSwap)->next[1 - direction]);

            bstNode *helper = (*toSwap)->next[direction];
            *p = *toSwap;
            (*toSwap)->next[direction] = toDel->next[direction];
            (*toSwap)->next[1 - direction] = toDel->next[1 - direction];
            (*toSwap) = helper;
        }
    }

    delete toDel;
}
