#include "node.h"


class treeNode {
public:
    int element;
    treeNode *left;
    treeNode *right;

    treeNode(int data, treeNode *lt = nullptr, treeNode *rt = nullptr)
    {
        element = data;
        left = lt;
        right = rt;
    }
};

class tree {
public:
    tree(int data = 0);
    int min_element( );
    int max_element( );
    bool contains( int  x );
    bool isEmpty( );
    void inorder();
    void insert(int x );
    void remove( int  x );
private:
    treeNode* root;
    treeNode* current; // Pointer to last node
};


