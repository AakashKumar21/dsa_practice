#include "main.h"

// As pointer is used data is not safe i.e vulnerable to accidental change.
int binSearch(const struct Array *arr, int key) // key: int to search
{
    int _l = 0;
    int _h = arr->size-1;
    int _mid;

    while(_l<=_h)
    {
        _mid = (_l + _h)/2;
        if(arr->arr[_mid] == key)
            return _mid;

        if (key > arr->arr[_mid]) _l = _mid + 1;
        else _h = _mid - 1;
    }
    return -1;
}