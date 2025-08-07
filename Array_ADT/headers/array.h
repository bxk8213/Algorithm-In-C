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
void swap(Array *arr, int i, int j);

void printArray(struct Array *arr);

#endif