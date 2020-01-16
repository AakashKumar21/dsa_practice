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

    int get_min(int i = 0); // returns index

    type reverse();

    int get_size() { return m_size; };

    void sort_bubble();

    void sort_merge();

    void sort_insertion();

    void sort_selection();

    type *begin() { return m_array; };

    type *end() { return &m_array[m_size]; };

    bool isSorted();

private:
    void _swap(type &t_a, type &t_b);

    void _merge(int low, int mid, int high);

};

template<typename type>
array<type>::array(unsigned int size) {
    m_array = new type[size];
    m_size = size; // for quickSort op
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
int array<type>::get_min(int i) {
    type min = m_array[i];
    int min_index = i;
    for (; i < m_size - 1; i++) {
        if (m_array[i] < min) {
            min = m_array[i];
            min_index = i;
        }
    }
    return min_index;
}

template<typename type>
void array<type>::sort_bubble() { // TODO
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

    for (int i = 1; i < m_size; i++) {
        type temp = m_array[i];
        int index = i;
        while (index > 0 && m_array[index - 1] > temp) {
            m_array[index] = m_array[index - 1];
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
void array<type>::sort_selection() {
    for (int i = 0; i < m_size - 1; i++) {
        for (int j = 0; j < m_size - 1; j++) {
            std::cout << m_array[j] << " ";
        }
        std::cout << "Min Index: " << get_min(i) << "\n";
        std::cout << "Min Value: " << m_array[get_min(i)] << "\n";
        _swap(m_array[i], m_array[get_min(i)]);
    }
}

template<typename type>
void array<type>::sort_merge() {
    int i, low, mid , high, p;

    // Outer loop for passes, total passes = log2(n)
    for (p = 2; p <= m_size - 1; p *= 2) {
        std::cout << "Pass" << p << "\n";
        // Size of array passed is doubled in each pass
        for (i = 0; i + p < m_size - 1; i = i + p) {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            std::cout<< low << ":" << mid << ":" << high << "\n";
            _merge(low, mid, high);
        }
    }
    std::cout<< low << ":" << mid << ":" << high << "\n";
    if (p / 2 < m_size) _merge(0, (p / 2 ) - 1, m_size );
}

// merging of two lists in same array
template<typename type>
void array<type>::_merge(int low, int mid, int high) {
    type *new_array = new type[high + 1];// temp array

    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (m_array[i] < m_array[j])
            new_array[k++] = m_array[i++];
        else
            new_array[k++] = m_array[j++];
    }
    for (; i <= mid; i++)
        new_array[k++] = m_array[i];
    for (; j <= high; j++)
        new_array[k++] = m_array[j];

    for (int i = low; i <= high; i++)
        m_array[i] = new_array[i];
}

#endif //DSA_CPP_ARRAY_ADT_H