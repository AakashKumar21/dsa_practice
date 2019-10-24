//
// Created by aakas on 10/13/2019.
//

#ifndef TEST_CPP_STACK_H
#define TEST_CPP_STACK_H

#include "linked_list.h"

template <typename type>
class stack {
private:
   int _top = -1;
   linked_list<type> *_list = nullptr;

public:
    stack(type data);
    stack();
    void push(type data);
    type pop();
    type get_data() { return _list->get_head_data(); }
    auto get_head_node();
    bool is_empty();
    int count() { return _top; };
};

template<typename type>
stack<type>::stack(type data) {
    _list = new linked_list<type> (data);
    _top = 1;
}

template<typename type>
stack<type>::stack() {
    _list = new linked_list<type> (NULL);
    _top = -1; // Data is still not initilised
}

template<typename type>
void stack<type>::push(type data) {
    // If stack is initilised without data then
    // call set_data of the head_node in the linked list
    if(_top == -1)
    {
        _list->get_head()->set_data(data);
        _top += 1;
        return;
    }
    _top += 1;
    _list->insert_as_head(new Node<type>(data));
    //std::cout<< "Count Inside:" << _top<< std::endl;
}

template<typename type>
type stack<type>::pop() {
    --_top;
//    if(_list->is_empty()) return
    return _list->delete_head();
}

template<typename type>
auto stack<type>::get_head_node() {
    return _list->get_head();
}

template<typename type>
bool stack<type>::is_empty() {
    if(_top == -1) return 1;
    else return 0;
}

#endif //TEST_CPP_STACK_H