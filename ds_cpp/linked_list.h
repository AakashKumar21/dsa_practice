//
// Created by aakas on 10/10/2019.
//
#include "node.h"
#ifndef TEST_CPP_LINKED_LIST_H
#define TEST_CPP_LINKED_LIST_H

/* FEATURES AND CHAR
 * 1. Always init with 1 Node, if no data is provided its set to null
*/

template <typename type>
class linked_list
{
private:
    Node<type> *_head = nullptr;
    Node<type> *_tail = nullptr; // Also tail
    unsigned int _count;

public:
    linked_list(type data);
    void push(type data);
    void insert_as_head( Node<type> * node);
    void insert_after( Node<type>* old_node, Node<type>* new_node);
    // Use  is_empty() before deleting otherwise it will return -1
    type delete_head();
    void insert_as_tail(type data);
    auto get_head() const { return _head; }
    // Returns 1 if empty
    auto is_empty() { return _head == nullptr; }
    type get_head_data() const;
};

template<typename type>
linked_list<type>::linked_list(type data) {
    _head = new Node<type>(data);
    _tail = _head;
    _count = 1;
}

template<typename type>
void linked_list<type>::push(type data) {
    _count++;
    _tail->set_next(new Node<type>(data));
    _tail = _tail->get_next();
}

template<typename type>
void linked_list<type>::insert_as_head(Node<type> *node) {
    node->set_next(_head);
    _head = node;
    _count++;
}

template<typename type>
type linked_list<type>::delete_head() {
    // Don't delete _head pointer
    // Just set count = -1
    if(_head->get_next() == nullptr)
    {
        if(_count == -1) throw "list is empty";
        _count = -1;
        return _head->get_data();
    }
    auto *tmp_ptr = _head;
    auto tmp_data = _head->get_data();
    _head = _head->get_next();
    delete tmp_ptr;
    _count--;
    return tmp_data;
}

template<typename type>
void linked_list<type>::insert_after(Node<type> *old_node, Node<type> *new_node) {
    new_node->set_next(old_node->get_next());
    old_node->set_next(new_node);
}

template <typename type>
void linked_list<type>::insert_as_tail(type data)
{
    insert_after(_tail, new Node<type>);
}

template<typename type>
type linked_list<type>::get_head_data() const {
    if(_count == -1) throw std::runtime_error("List is empty");
    return _head->get_data();
}

#endif //TEST_CPP_LINKED_LIST_H