#include <stdio.h>

/*
    Nested Recursion:
        passing function itself as a parameter.

    
*/

int nestedRecursion(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    return nestedRecursion(nestedRecursion((n + 11)));
}

int main()
{
    int n = 5;

    int r = nestedRecursion(5);

    printf("%d\n",r);

    return 0;
}