#include <stdio.h>

void headRecursion(int n);

int main()
{
    int n = 10;

    headRecursion(10);

    return 0;
}

/*
    Recursive call is the first statement after the base case,
    Whatever work will be done after the recursive call

    Expected output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    Actual Printed: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    Time Complexity : O(n) - has to print all elements
    Space Complexity: O(n) - will have stack frame for all recursive call.
*/
void headRecursion(int n)
{
    if(n < 0)
    {
        return;
    }
    headRecursion(n-1);
    printf("%d, ", n);
}