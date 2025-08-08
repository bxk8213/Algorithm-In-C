#include <stdbool.h>
#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array{
    int A[10];
    int length;
}Array;

void reverse(struct Array *arr, int length);
void shiftLeft(Array *arr);
void shiftRight(Array *arr);
void rotateLeft(Array *arr);
bool isSorted(Array arr);
void negLeftSide(Array *arr);

Array * mergeSortedArray(Array *arr1, Array *arr2);
Array * unionNotSorted(Array *arr1, Array *arr2);
Array * unionSorted(Array *arr1, Array *arr2);
Array * intersectionNotSorted(Array *arr1, Array *arr2);
Array * intersectionSorted(Array *arr1, Array *arr2);
int singleMissingNumber(Array *arr);
void formulaSMN(Array *arr);
void multipleMissingElements(Array *arr);
void unsortedMME(Array *arr);
void sortedDuplicate(Array *arr);
void countSortedDuplicate(Array *arr);
void duplicateHash(Array *arr);
void targetSumUnsorted(Array *arr, int target);
void targetSumUnsortedHash(Array *arr, int target);
void targetSumSorted(Array *arr, int target);

int max(Array *arr);
void swap(Array *arr, int i, int j);
void printArray(struct Array *arr);

#endif