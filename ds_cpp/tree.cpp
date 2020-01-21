//
// Created by aakas on 1/16/2020.
//

#include "tree.h"

tree::tree(int data) {
    root = new treeNode(data);
    current = root;
}

void tree::insert(int x) {
    if (x > current->element) {
        current->right = new treeNode(x);
    }
    else current->left = new treeNode(x);
}
