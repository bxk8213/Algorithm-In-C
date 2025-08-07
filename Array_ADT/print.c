#include <stdio.h>
#include "headers/array.h"

void printArray(struct Array *arr)
{
    for(int i = 0; i < (*arr).length; i++)
    {
        printf("%d ", (*arr).A[i]);
    }
}
