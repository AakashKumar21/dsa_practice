//
// Created by aakas on 10/10/2019.
//

#ifndef TEST_CPP_NODE_H
#define TEST_CPP_NODE_H

template <typename Type>
class Node
{
private:
        Type _data;
        Node *_next;

public:
    Node(Type data, Node *next = nullptr);
    // Data Setter n Getter
    Type get_data() const;
    void set_data(Type data);
    // Node set_next, get_next
    void set_next(Node* next);
    auto get_next() const;
    // Check Tail
    bool is_tail() const;

};

template<typename Type>
Node<Type>::Node(Type data, Node *next) {
    _data = data;
    _next = next;
}

template<typename Type>
void Node<Type>::set_next(Node *next) { _next = next; }

template<typename Type>
Type Node<Type>::get_data() const { return _data; }

template<typename Type>
void Node<Type>::set_data(Type data) { _data = data; }

template<typename Type>
auto Node<Type>::get_next() const { return _next; }

template<typename Type>
bool Node<Type>::is_tail() const { return _next == nullptr; }


#endif //TEST_CPP_NODE_H
