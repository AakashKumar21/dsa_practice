#include "linked_list.h"
#include <iostream>

template<typename type>
linked_list<type>::linked_list(type data) {
    _head = new Node<type>(data);
    _tail = _head;
    if(data == NULL) _count = -1;
    else _count = 1;
}

template<typename type>
void linked_list<type>::push(type data) {
//    if(_head == nullptr){
    if(_count == -1){
        _head = new Node<type>(data); // As list is empty, there is no head
        _tail = _head;
        _count = 1; // As in empty linked list, _count = -1
    }
    else {
    _count++;
    _tail->set_next(new Node<type>(data));
    _tail = _tail->get_next();
    }
}

template<typename type>
void linked_list<type>::insert_as_head(Node<type> *node) {
    node->set_next(_head);
    _head = node;
    if (_head == nullptr) _count = 1;
    else _count++;
}



template<typename type>
type linked_list<type>::delete_head() {
    if(_head->get_next() == nullptr )
//    if(_head == nullptr )
    {
        if(_count == -1) throw std::runtime_error("List is empty");
        _count = -1;
        auto tmp = _head->get_data();
        delete _head;
        _head,_tail = nullptr;
        return tmp; // Method Ends here
    }
    else{
        auto tmp_ptr = _head;
        auto tmp_data = _head->get_data();
        _head = _head->get_next();
        delete tmp_ptr;
        _count--;
        return tmp_data;
    }
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

template<typename type>
void linked_list<type>::insert_as_head(type data) {
    auto node =  new Node<type>(data);
    if(_head == nullptr) // Linked list is empty
    {
        node->set_next(nullptr); // TODO
        _tail = node;
    }
    else
        node->set_next(_head);
    _head = node;
    if (_head == nullptr) _count = 1;
    else _count++;
}

template<typename type>
void linked_list<type>::push(Node<type> *node) {
//    if(_head == nullptr){
    if(_count == -1){
        _head = node; // As list is empty, there is no head
        _tail = _head;
        _count = 1; // As in empty linked list, _count = -1
    }
    else {
        _count++;
        _tail->set_next(node);
        _tail = _tail->get_next();
    }
}

