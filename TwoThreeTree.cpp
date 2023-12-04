//
// Created by igo-j on 04.12.2023.
//

#include "TwoThreeTree.h"
#include <algorithm>

TwoThreeTree::node *TwoThreeTree::Union(TwoThreeTree::node *root1, TwoThreeTree::node *root2) {
    if(!root1) return root2;
    if(!root2) return root1;

    if(root1->h == root2->h){
        node *p = new node(std::max(root1->key, root2->key), root1->h + 1,
                           root1, nullptr, root2);
        return p;
    }
}
