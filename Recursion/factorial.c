#include <stdio.h>

int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}

int main()
{
    int n = 5;
    int r;
    r = factorial(5);

    printf("%d\n", r);

    return 0;
}