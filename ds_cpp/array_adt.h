//
// Created by aakas on 1/8/2020.
//

#ifndef DSA_CPP_ARRAY_ADT_H
#define DSA_CPP_ARRAY_ADT_H

#include <bits/functexcept.h>
#include <iostream>

template<typename type>
class array {
private:
    type *m_array; // pointer to array
    unsigned int m_size; // Size of array

public:
    array(unsigned int size);

    array(type *t_array, unsigned int t_size);

    type *get_head(); // return pointer to array i.e to 1st element of array
    type &operator[](unsigned int i);

    int search_binary(type key); // TODO , not working for floats

    // Returns index

    type get_max();

    type get_min();

    type reverse();

    int get_size() { return m_size; };

    void Sort_bubble(bool ascending); //ascending if 1, else descending TODO

    void sort_insertion();

    type *begin() { return m_array; };

    type *end() { return &m_array[m_size - 1]; };

    bool isSorted();

private:
    void _swap(type& t_a, type& t_b);
    // Shifts element to right till index i
    void _shift(int i);
};

template<typename type>
array<type>::array(unsigned int size) {
    m_array = new type[size];
    m_size = size;
}

template<typename type>
type *array<type>::get_head() {
    return m_array;
}

template<typename type>
type &array<type>::operator[](unsigned int i) {
    if (i >= m_size) std::__throw_out_of_range("Out of Range");
    return m_array[i];
}

template<typename type>
int array<type>::search_binary(type key) {
//RECURSIVE
//    int mid;
//    if(l<=h)
//    {
//        mid = (l+h)/2;
//        if(key == m_array[mid]) return mid;
//        else if (key > m_array[mid]) search_binary(m_array,key,mid+1,h);
//        else search_binary(m_array,key,l,h-1);
//    }
//    return -1;

//ITERATIVE
    int l = 0;
    int h = m_size - 1;
    int mid;

    while (l <= h) {
        mid = (l + h) / 2;
        if (m_array[mid] == key)
            return mid;

        if (key > m_array[mid]) l = mid + 1;
        else h = mid - 1;
    }
}

template<typename type>
// Returns index
type array<type>::get_max() {
    type max = m_array[0];
    for (int i = 1; i < m_size; i++)
        if (m_array[i] > max) max = m_array[i];
    return max;
}

template<typename type>
type array<type>::get_min() {
    type min = m_array[0];
    for (int i = 1; i < m_size; i++)
        if (m_array[i] < min) min = m_array[i];
    return min;
}

template<typename type>
void array<type>::Sort_bubble(bool ascending) { // TODO
    bool swap_flag;

    //Outer loop for pass
    for (int pass = 0; pass < m_size; pass++) {
        swap_flag = false;
        for (int j = 0; j < m_size - pass - 1; ++j) {
            if (m_array[j] > m_array[j + 1]) {
                _swap(m_array[j], m_array[j + 1]);
                swap_flag = true;
            }
            //Array is sorted
        }
        if (!swap_flag) break;
    }
}

template<typename type>
type array<type>::reverse() {
    type *new_arr = new type[m_size];
    for (int i = 0, j = m_size - 1; i < m_size; ++i, --j) {
        new_arr[i] = m_array[j];
    }
    delete[] m_array;
    m_array = new_arr;

}

template<typename type>
bool array<type>::isSorted() { // TODO, not working for floats
    for (int i = 0; i < m_size - 1; ++i) {
        if (m_array[i] > m_array[i + 1]) return false;
    }
    return true;
}

template<typename type>
array<type>::array(type *t_array, unsigned int t_size) {
    m_array = t_array;
    m_size = t_size;
}

template<typename type>
void array<type>::sort_insertion() {

    // 1st element is already sorted

    for(int i=1 ; i<m_size ; i++)
    {
        type temp = m_array[i];
        int index = i;
        while ( index > 0 && m_array[index -1] > temp)
        {
            m_array[index] = m_array[index -1];
            --index;
        }
        m_array[index] = temp;
    }
}

template<typename type>
void array<type>::_swap(type &t_a, type &t_b) {
    type temp;
    temp = t_a;
    t_a = t_b;
    t_b = temp;
}

template<typename type>
void array<type>::_shift(int i) {
//    type element = m_array[m_size]; // elem
//    for(int k=0 ; k < i; k++)
//    {
//        m_array[i]
//    }
}

#endif //DSA_CPP_ARRAY_ADT_H