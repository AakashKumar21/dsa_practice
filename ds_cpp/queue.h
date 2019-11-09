#ifndef DSA_CPP_PRACTICE_QUEUE_H
#define DSA_CPP_PRACTICE_QUEUE_H

#include "linked_list.h"

template <typename type>

class queue {
private:
    linked_list<type> *_list;
    Node<type> *_tail;
    int _count;

public:
    void enq_front(type data);
    void enq_rear(type data);
    type deq_front();
    type deq_rear();
    type get_front();
    int get_count();
    queue(type data);
};


#endif //DSA_CPP_PRACTICE_QUEUE_H
