#ifndef DSA_CPP_PRACTICE_QUEUE_H
#define DSA_CPP_PRACTICE_QUEUE_H

#include "linked_list.h"

template<typename type>

class queue {
private:
    linked_list<type> *_list;
//    Node<type> *_tail;
    int _count;

public:
    // EnQ
    void enq_front(type data);

    void enq_rear(type data);

    // DeQ
    type deq_front();

    type deq_rear();

    //Getters
    type get_front();

    type get_rear();

    int get_count();

    queue(type data);
};


template<typename type>
queue<type>::queue(type data) {
    _list = new linked_list<type>(data);
    _count = 1;
}

template<typename type>
void queue<type>::enq_rear(type data) {
    auto node = new Node<type>(data);
    _list->push(node);
//    _tail = node;
    _count++;
    // When list is empty
//    if(_list->is_empty()) this->queue(data);
}

template<typename type>
type queue<type>::deq_front() {
    _count == 1 ? (_count = -1) : (_count--);
    if (_count == -1) throw std::runtime_error("Queue is empty");
    return _list->delete_head();
}

template<typename type>
type queue<type>::get_front() {
    return _list->get_head_data();
}

template<typename type>
type queue<type>::get_rear() {
    return _list->get_tail()->get_data();
}

template<typename type>
void queue<type>::enq_front(type data) {
    _list->insert_as_head(data);
    _count++;
}

template<typename type>
int queue<type>::get_count() {
    return _count;
}

template<typename type>
type queue<type>::deq_rear() {
//    if(_count == -1 ) throw std::runtime_error("Queue is empty");
//    auto preptr = _list->get_head();
//    if(_count == 1)
//    {
//        type tmp_data = preptr->get_data();
//        delete preptr;
//        _tail = nullptr;
//        _count = -1;
//        return tmp_data;
//    }
//    while(true)
//    {
//        if (preptr->get_next() == _list->get_tail()) {
//            type tmp_data = preptr->get_next()->get_data();
//            delete preptr->get_next();
//            preptr->set_next(nullptr);
//            _tail = preptr;
//            _count--;
//            return tmp_data;
//        } else
//        preptr = preptr->get_next();
//    }
    return _list->pop();
}


#endif //DSA_CPP_PRACTICE_QUEUE_H
