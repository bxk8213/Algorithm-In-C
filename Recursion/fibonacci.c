
/*
    Fibonacci:
        Adding the second last and last term to get the next term.

        Base number 0 and 1.
        Recursive case: f(n-2) + f(n-1) = f(n)
        
*/

#include <stdio.h>


/*
    Expected Value: 5 for fib(5), 55 for fib(10), 21 for fib(8)
    Actual Value: 5 for fib(5), 55 for fib(10), 21 for fib(8)

    Time Complexity: O(2^n) - very inefficient
    Space Complexity: O(n)
*/
int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return fib(n-2) + fib(n-1);
}

/*
    Memoization:
        Storing the value of function calls so that we can use that value when we need to do same functional call.

    Expected Value: 5 for memfib(5), 55 for memfib(10), 21 for memfib(8)
    Actual Value: 5 for memfib(5), 55 for memfib(10), 21 for memfib(8)

    Time Complexity: O(n) - faster than other fib
    Space Complexity: O(n)
*/

int FUN[10];

int memfib(int n)
{
    if(n <= 1)
    {
        FUN[n] = n;
        return n;
    }
    else{
        if(FUN[n-2] == -1)
        {
            FUN[n-2] = memfib(n-2);
        }

        if(FUN[n-1] == -1)
        {
            FUN[n-1] = memfib(n-1);
        }

        FUN[n] = FUN[n-2] + FUN[n-1];
        return FUN[n-2] + FUN[n-1];
    }
}

int main()
{

    for(int i = 0; i < 10; i++)
    {
        FUN[i] = -1;
    }

    int r;
    r = fib(8);

    printf("%d\n", r);

    r = memfib(8);
    printf("%d\n", r);


    return 0;
}