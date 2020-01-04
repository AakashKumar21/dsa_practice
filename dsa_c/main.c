#include <stdio.h>
#include "search_iterative.h"

int main() {
    struct Array arr = {(int*)malloc(10* sizeof(int)), 10};
    for (int i=0 ; i < 10; i++)
    {
        arr.arr[i] = i ;
    }
    printf("Index: %d", binSearch(&arr,33));
    return 0;
}