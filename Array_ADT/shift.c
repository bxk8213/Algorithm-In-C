#include <stdio.h>
#include "headers/array.h"

void shiftLeft(Array *arr)
{
    int i;
    for(i = 1; i < arr->length; i++)
    {
        (*arr).A[i-1] = (*arr).A[i];
    }
    (*arr).A[i-1] = 0;
}

void shiftRight(Array *arr)
{
    int i;
    for(i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[i+1] = arr->A[i];
    arr->A[i] = 0;
}