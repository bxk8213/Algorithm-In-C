#include <stdio.h>
#include <stdlib.h>
#include "headers/array.h"

// Can't increase size of array, because we have set constant size of array in struct
Array * unionNotSorted(Array *arr1, Array *arr2)
{
    Array *arr3 = (Array *) malloc(sizeof(Array));

    int i, j, k;
    i = j = k = 0;

    int length = arr3->length;

    for(i = 0, k = 0; i < arr1->length; i++, k++)
    {
        arr3->A[length++] = arr1->A[i];
    }

    for(j = 0; j < arr2->length; j++)
    {
        for(k = 0; k < length && arr2->A[j] != arr3->A[k]; k++);
        if(k == length)
        {
            arr3->A[length++] = arr2->A[j];
        }
    }

    arr3->length = length;
    return arr3;

}

Array * unionSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = (Array *) malloc(sizeof(Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] > arr2->A[j])
        {
            arr3->A[k++] = arr2->A[j++];
        }
        else if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i++];
    }

    for(; j < arr1->length; j++)
    {
        arr3->A[k++] = arr2->A[j++];
    }

    arr3->length = k;
    return arr3;
    
}