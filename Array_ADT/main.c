#include <stdio.h>
#include "headers/array.h"

// void reverse(struct Array *arr, int length);

int main()
{
    // struct Array arr = { {8, 3, 9, 15, 6, 10, 7, 2, 12, 4}, 10 };

    // struct Array arr1 = { { 2, 4, 6, 8, 10 }, 5 };

    // struct Array arr2 = { { 1, 10, 5, 4, 9 }, 5 };

    // struct Array sortedArr1 = { { 2, 4, 6, 8, 10, 14, 16}, 7 };

    // struct Array sortedArr2 = { { 1, 2, 6, 7, 10 }, 5 };

    // struct Array sortedArr = { { 11, 12, 12, 17, 18, 18, 18, 19}, 8 };

    // struct Array sortedNatArr = { { 1, 2, 3, 4, 6, 7, 8 }, 7 };

    // struct Array unSortedArr = { { 1, 8, 3, 20, 6, 12, 5, 14, 11, 2}, 10 };

    struct Array sortedArr = { { 1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10 };

    struct Array *arr3;

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

    // struct Array arr4 = { { 2, 4, -6, -1, 10, -5, 9, 4, 7, -3 }, 10 };
    // negLeftSide(&arr4);

    // arr3 = mergeSortedArray(&arr1, &arr2);

    // arr3 = unionNotSorted(&arr1, &arr2);
    // printArray(arr3);
    // printf("\n");

    // arr3 = unionSorted(&sortedArr1, &sortedArr2);
    // printArray(arr3);
    // printf("\n");

    // arr3 = intersectionNotSorted(&arr1, &arr2);
    // printArray(arr3);
    // printf("\n");

    // arr3 = intersectionSorted(&sortedArr1, &sortedArr2);

    // printArray(arr3);
    // printf("\n");

    // int missingNum = singleMissingNumber(&sortedArr);
    // printf("%d\n", missingNum);

    // formulaSMN(&sortedNatArr);

    // multipleMissingElements(&sortedArr);

    // unsortedMME(&arr2);

    // sortedDuplicate(&sortedArr);

    // countSortedDuplicate(&sortedArr);

    // duplicateHash(&sortedArr);

    // targetSumUnsorted(&unSortedArr, 13);

    // targetSumUnsortedHash(&unSortedArr, 13);

    targetSumSorted(&sortedArr, 10);

    return 0;
}