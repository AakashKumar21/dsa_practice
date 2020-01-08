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

#endif //DSA_CPP_ARRAY_ADT_H