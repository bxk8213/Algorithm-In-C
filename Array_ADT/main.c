#include <stdio.h>
#include "headers/array.h"

// void reverse(struct Array *arr, int length);

int main()
{
    struct Array arr = { {8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10 };

    struct Array arr1 = { { 2, 4, 6, 8, 10 }, 5 };

    struct Array arr2 = { { 2, 4, -6, -1, 10, -5, 9, 4, 7, -3 }, 10 };

    // reverse(&arr, arr.length);

    // shiftLeft(&arr);

    // shiftRight(&arr);


    // rotateLeft(&arr);
    // printArray(&arr);
    // printf("\n");
    // rotateLeft(&arr);
    // printArray(&arr);
    // printf("\n");
    // rotateLeft(&arr);
    // printArray(&arr);
    // printf("\n");
    // rotateLeft(&arr);
    // printArray(&arr);
    // printf("\n");
    // rotateLeft(&arr);
    // printArray(&arr);
    // printf("\n");
    // rotateLeft(&arr);
    // printArray(&arr);

    // bool sorted = isSorted(arr1);
    // printf("%d\n", sorted);

    negLeftSide(&arr2);
    printArray(&arr2);

    return 0;
}