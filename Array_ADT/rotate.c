#include <stdio.h>
#include "headers/array.h"


void rotateLeft(Array *arr)
{
    int i;
    int temp = arr->A[0];
    for(i = 1; i < arr->length; i++)
    {
        arr->A[i-1] = arr->A[i];
    }
    arr->A[i-1] = temp;
}