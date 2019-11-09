//
// Created by aakas on 11/9/2019.
//

#include "queue.h"

template<typename type>
queue<type>::queue(type data) {
    _list = new linked_list<type>(data);
    _tail = _list->get_head();
}

template<typename type>
void queue<type>::enq_rear(type data){
    auto node = new Node<type>(data);
    _list->push(node);
    _tail = node;
    // When list is empty
//    if(_list->is_empty()) this->queue(data);
}

template<typename type>
type queue<type>::deq_front() {
    return _list->delete_head();
}

template<typename type>
type queue<type>::get_front() {
    return _list->get_head_data();
}


