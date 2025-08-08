#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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

/*
    Worst case Analysis:
    Time Complexity : O(length of arr1 * length of arr2)
    Space Complexity: O(length of arr1 + length of arr2)
*/

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

/*
    Worst case Analysis:
    Time Complexity : O(length of arr1 + length of arr2)
    Space Complexity: O(length of arr1 + length of arr2)
*/
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

/*
    Worst case Analysis
    Time Complexity: O(length of arr1 * length of arr2)
    Space Complexity: O(length of arr1 + length of arr2)

*/
Array * intersectionNotSorted(Array *arr1, Array *arr2)
{
    int i, j, k;

    i = j = k = 0;

    Array *arr3 = (Array *) malloc(sizeof(Array));

    for(i = 0; i < arr1->length; i++)
    {
        for(j = 0; j < arr2->length && (arr1->A[i] != arr2->A[j]); j++);
        if(j < arr2->length)
        {
            arr3->A[k++] = arr2->A[j];
        }
    }

    arr3->length = k;
    return arr3;
}

Array * intersectionSorted(Array *arr1, Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = (Array *) malloc(sizeof(Array));

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    return arr3;
}

/*
    Using index difference

    Time Complexity: O(length of arr)
    Space Complexity: O(1)
*/
int singleMissingNumber(Array *arr)
{
    int i;
    int missingNumber;
    int diff = arr->A[0] - 0;
    for(i = 0; i < arr->length && (arr->A[i] - i == diff); i++);
    if(i < arr->length)
    {
        missingNumber = arr->A[0] + i;
    }

    return missingNumber;
}

/*
    Works for Natural Number

    Time Complexity: O(length of arr)
    Space Complexity: O(1)
*/
void formulaSMN(Array *arr)
{
    int i, sum = 0;
    int nNaturalNumSum, missingNum;
    for(i = 0; i < arr->length; i++)
    {
        sum += arr->A[i];
    }

    nNaturalNumSum = (arr->A[arr->length-1] * (arr->A[arr->length-1] + 1)) / 2;

    missingNum = nNaturalNumSum - sum;

    printf("Missing Num: %d\n", missingNum);

}

/*

    Missing elements in a sorted array

    Time Complexity: O(length of arr * #of missing element)
    Space Complexity: O(1)
*/

void multipleMissingElements(Array *arr)
{
    int diff = arr->A[0] - 0;

    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] - i != diff)
        {
            while(diff + i != arr->A[i])
            {
                printf("%d ", diff + i);
                diff++;
            }

            /*
            Professor method
            while(diff < arr->A[i] - i)
            {
                printf("%d ", diff + i);
                diff++;
            }
            */
        }
    }
}

/*
    Better approach, if space is not limited.

    Time Complexity: O(length of arr + max)
    Space Complexity: O(max)
*/

void unsortedMME(Array *arr)
{
    int max = arr->A[0];

    for(int i = 1; i < arr->length; i++)
    {
        if(max < arr->A[i])
        {
            max = arr->A[i];
        }
    }

    int *arr2 = (int *) calloc(max, sizeof(int));

    for(int i = 0; i < max; i++)
    {
        arr2[arr->A[i]]++;
    }

    for(int i = 1; i < max; i++)
    {
        if(arr2[i] == 0)
        {
            printf("%d ", i);
        }
        
    }
}


/*
    Duplicate in sorted array
*/
void sortedDuplicate(Array *arr)
{
    int lastDuplicate = 0;

    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == arr->A[i+1] && arr->A[i] != lastDuplicate)
        {
            printf("%d ", arr->A[i]);
            lastDuplicate = arr->A[i]; 
        }
    }
}

/*
    Time Complexity: O(length of arr) - while loop is negligible
    Space Complexity: O(1);
*/
void countSortedDuplicate(Array *arr)
{
    int count = 0;
    int totalCount = 0;
    for(int i = 0; i < arr->length; i++)
    {
        if(arr->A[i] == arr->A[i+1])
        {
            int j = i+1;

            while(arr->A[i] == arr->A[j])
            {
                j++;
            }
            count = j - i;
            totalCount += count;
            printf("%d appear %d times\n", arr->A[i], j - i);
            i = j - 1; // after this condition i moves 1 step ahead, so if we put in place of j, i will miss number.

        }
    }
    printf("%d\n", totalCount);
}

/*
    Duplicate in sorted/unsorted array using HashTable

    Time Complexity : O(length of arr + max)
    Space Complexity : O(max)
*/

void duplicateHash(Array *arr)
{
    int max = arr->A[0];

    for(int i = 1; i < arr->length; i++)
    {
        if(max < arr->A[i])
        {
            max = arr->A[i];
        }
    }

    int *arr2 = (int *) calloc(max, sizeof(int));

    for(int i = 0; i < max; i++)
    {
        arr2[arr->A[i]]++;
    }

    int totalCount = 0;
    for(int i = 1; i < max; i++)
    {
        if(arr2[i] > 1)
        {
            totalCount += arr2[i];
            printf("%d appears %d times\n", i, arr2[i]);
        }
    }

    printf("Total missing: %d\n", totalCount);

}

/*
    Using two pointer

    Time Complexity: O(i * j) - quadratic time
    Space Complexity: O(1) - constant time
*/
void targetSumUnsorted(Array *arr, int target)
{
    int i, j;

    for(i = 0; i < arr->length - 1; i++)
    {
        for(j = i + 1; j < arr->length; j++)
        {
            if(arr->A[i] + arr->A[j] == target)
            {
                printf("%d + %d = %d\n", arr->A[i], arr->A[j], target);
            }
        }
    }
}

/*
    Target sum for unsorted array using HashTable
    Time Complexity: O(length of arr)
    Space Complexity: O(range)
*/

void targetSumUnsortedHash(Array *arr, int target)
{
    int range = max(arr);

    int *H = (int *) calloc(range, sizeof(int));

    for(int i = 0; i < arr->length; i++)
    {
        if(H[target - arr->A[i]] != 0)
        {
            printf("%d + %d = %d\n", arr->A[i], target - arr->A[i], target);
        }
        H[arr->A[i]]++;
    }
}

/*
    Time Complexity: O(length of arr) - linear time
    Space Complexity: O(1) - constant space
*/
void targetSumSorted(Array *arr, int target)
{
    int i = 0,
    j = arr->length - 1;

    while(i < j)
    {
        if(arr->A[i] + arr->A[j] == target)
        {
            printf("%d + %d = %d\n", arr->A[i], arr->A[j], target);
            i++;
            j--;
        }
        else if(arr->A[i] + arr->A[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
        
    
}


int max(Array *arr)
{
    int maximum = arr->A[0];

    for(int i = 0; i < arr->length; i++)
    {
        if(maximum < arr->A[i])
        {
            maximum = arr->A[i];
        }
    }

    return maximum;
}

void swap(Array *arr, int i, int j)
{
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}

void printArray(struct Array *arr)
{
    for(int i = 0; i < (*arr).length; i++)
    {
        printf("%d ", (*arr).A[i]);
    }
}

