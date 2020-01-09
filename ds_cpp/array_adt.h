//
// Created by aakas on 1/8/2020.
//

#ifndef DSA_CPP_ARRAY_ADT_H
#define DSA_CPP_ARRAY_ADT_H

template<typename type>
class array {
private:
    type *m_array; // pointer to array
    unsigned int m_size; // Size of array

public:
    array(unsigned int size);

    type *get_head(); // return pointer to array i.e to 1st element of array
    type &operator[](unsigned int i);

    int search_binary(int key);

    const // Returns index

    type get_max();

    type get_min();

    type reverse();

    int get_size() { return m_size; };

    void sort(bool ascending); //ascending if 1, else descending

    type *begin() { return m_array; };

    type *end() { return &m_array[m_size - 1]; };
};

template<typename type>
array<type>::array(unsigned int size) {
    m_array = new int[size];
    m_size = size;
}

template<typename type>
type *array<type>::get_head() {
    return m_array;
}

template<typename type>
type &array<type>::operator[](unsigned int i) {
    return m_array[i];
}

template<typename type>
int array<type>::search_binary(int key) {
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
const // Returns index
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
void array<type>::sort(bool ascending) {
    if (ascending) {

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

#endif //DSA_CPP_ARRAY_ADT_H