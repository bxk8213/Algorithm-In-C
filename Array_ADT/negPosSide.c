#include <stdio.h>
#include "headers/array.h"


void negLeftSide(Array *arr)
{
    int i = 0,
    j = (arr->length)-1;

    while(i <= j)
    {
        while(arr->A[i] < 0)
        {
            i++;
        }

        while(arr->A[j] >= 0)
        {
            j--;
        }

        if(i < j)
        {
            swap(arr, i, j);
        }
    }
    
}


void swap(Array *arr, int i, int j)
{
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}