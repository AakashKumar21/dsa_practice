//
// Created by aakas on 11/9/2019.
//

#include "queue.h"

template<typename type>
queue<type>::queue(type data) {
    _list = new linked_list<type>(data);
    _tail = _list->get_head();
    _count = 1;
}

template<typename type>
void queue<type>::enq_rear(type data){
    auto node = new Node<type>(data);
    _list->push(node);
    _tail = node;
    _count++;
    // When list is empty
//    if(_list->is_empty()) this->queue(data);
}

template<typename type>
type queue<type>::deq_front() {
    return _list->delete_head();
    _count--;
}

template<typename type>
type queue<type>::get_front() {
    return _list->get_head_data();
}

template<typename type>
void queue<type>::enq_front(type data) { //TODO
    _list->insert_as_head(data);
    _count ++;
}

template<typename type>
int queue<type>::get_count() {
    return _count;
}

template<typename type>
type queue<type>::deq_rear() {
    auto preptr = _list->get_head();
    while(true)
    {
        if (preptr->get_next() == _tail) {
            type tmp_data = preptr->get_next()->get_data();
            delete preptr->get_next();
            _tail = preptr;
            return tmp_data;
        }
        preptr = preptr->get_next();
    }
}
