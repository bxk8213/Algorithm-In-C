#include <stdio.h>

/*
    Tail Recursion: 
        Last statement of the function call.

    Expected Output: 5, 4, 3, 2, 1, 0
    Actual Output: 
*/

void tailRecursion(int n)
{
    // Base Case
    if(n < 0)
    {
        return;
    }
    printf("%d, ", n);
    // Recursive call
    tailRecursion(n-1);
}

int main()
{
    int n = 5;

    tailRecursion(n);
}

