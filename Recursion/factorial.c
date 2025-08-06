#include <stdio.h>

/*
    Factorial:
        Multiplying from n to 1, i.e n * (n-1) * (n-2) * ... * 3 * 2 * 1

        0! = 1
        1! = 1

    Expected Output: 20 for factorial(5)
    Actual Output: 20 for factorial(5)

    Time Complexity: 0(n)
    Space Complexity: 0(n)
*/
int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}

// int main()
// {
//     int n = 5;
//     int r;
//     r = factorial(5);

//     printf("%d\n", r);

//     return 0;
// }