#include <stdio.h>
#include <stdbool.h>
#include "headers/array.h"

// Works for sorted elements in ascending order
bool isSorted(Array arr)
{
    for(int i = 1; i < arr.length; i++)
    {
        if(arr.A[i] < arr.A[i-1])
        {
            return false;
        }
    }
    return true;
}