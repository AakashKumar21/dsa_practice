//
// Created by aakas on 10/10/2019.
//
#include "node.h"
#ifndef TEST_CPP_LINKED_LIST_H
#define TEST_CPP_LINKED_LIST_H

/* FEATURES AND CHAR
 * 1. Always init with 1 Node
*/

template <typename type>
class linked_list
{
private:
    Node<type> *_head = nullptr;
    Node<type> *_tail = nullptr;
    unsigned int _count;

public:
    linked_list(type data);
    void push(type data);
    void push(Node<type> *node);
    void insert_as_head( Node<type> * node);
    void insert_as_head(type data);
    void insert_after( Node<type>* old_node, Node<type>* new_node);
    // Use  is_empty() before deleting otherwise it will return -1
    type delete_head();
    void insert_as_tail(type data);
    auto get_head() const { return _head; }
    auto get_tail() const { return _tail; }
    // Returns 1 if empty
    auto is_empty() { return _count == -1; }
    type get_head_data() const;
    int get_count() { return _count;}
};

#endif //TEST_CPP_LINKED_LIST_H