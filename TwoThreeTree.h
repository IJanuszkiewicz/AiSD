//
// Created by igo-j on 04.12.2023.
//

#ifndef KOLEJKI_TWOTHREETREE_H
#define KOLEJKI_TWOTHREETREE_H


class TwoThreeTree {
    struct node {
        int h;
        int key;
        node *left, *middle, *right;

        node(int key, int h = 0, node *left = nullptr, node *middle = nullptr, node *right = nullptr) :
                key(key), h(h), left(left), middle(middle), right(right) {}
    };

    node *root;

public:
    static node *Union(node *root1, node *root2);
    node *Union(node* root){return Union(root, this->root);}
};


#endif //KOLEJKI_TWOTHREETREE_H
