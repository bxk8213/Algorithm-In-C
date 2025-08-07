#include <stdio.h>
#include <stdlib.h>
#include "headers/array.h"

/*
    Time Complexity: Theta(length of arr1 + length of arr2)
    Space Complexity: Theta(length of arr1 + length of arr2)
*/
struct Array * mergeSortedArray(Array *arr1, Array *arr2)
{
    int i = 0, j = 0, k = 0;

    

    Array *arr3 = (Array *)malloc(sizeof(Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }

    for(; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for(; j < arr2->length; j++)
    {
        arr3->A[k++] = arr1->A[j];
    }

    arr3->length = arr1->length + arr2->length;

    return arr3;
    
}
