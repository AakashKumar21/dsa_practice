#include <stdio.h>
#include "BinSearch.h"

int main() {
    struct Array arr = {(int*)malloc(10* sizeof(int)), 10};
    //             {0,1,2,4,4 ,5 ,6 ,7 ,8 ,9 }
    int temp[10] = {2,6,7,9,23,45,56,78,98,234};
    arr.arr = temp;
    printf("Index(Iterative): %d\n", BinSearch_iterative(&arr,98));
    printf("Index(Recursive): %d\n", BinSearch_iterative(&arr,98));
    return 0;
}