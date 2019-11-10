//
// Created by aakas on 11/10/2019.
//

#ifndef DSA_CPP_PRACTICE_GRAPH_H
#define DSA_CPP_PRACTICE_GRAPH_H


class Graph {
private:
    int** _adj_matrix;
    int _size;

public:
    Graph(int size);
    void add_edge(int i, int j);
    void remove_edge(int i, int j);
    bool contains_edge(int i, int j);
    void print_as_matrix();
};


#endif //DSA_CPP_PRACTICE_GRAPH_H
