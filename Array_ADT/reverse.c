#include <stdio.h>
#include "headers/array.h"

/*
    Expected Output: 4 12 2 7 10 6 15 9 3 8 
    Actual Output: 4 12 2 7 10 6 15 9 3 8 
    Time Complexity: O(length)
    Space Complexity: O(1)
*/

void reverse(struct Array *arr, int length)
{
    int temp;

    for(int i = 0; i < (length / 2); i++)
    {
        temp = (*arr).A[i];
        (*arr).A[i] = (*arr).A[length - i - 1];
        (*arr).A[length - i - 1] = temp;
    }

}

