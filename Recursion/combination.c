/*
    Combination: 
        How many ways we can do something.
*/

#include <stdio.h>
#include "factorial.c"


/*
    Formula to find combination:
        nCr = n! / ( r! * (n-r)! )

    Time Complexity: O(n)
    Space Complexity: O(n) 
*/

int combination(int n, int r)
{
    int var1, var2, var3;

    var1 = factorial(n);
    var2 = factorial(r);
    var3 = factorial(n-r);

    return var1 / ( var2 * var3);
}

/*

    Using Pascal Triangle:
        Adding the previous two numbers

    Expected Output: 10 for recCombination(5, 2)
    Actual Output: 10 for recCombination(5, 2)

    Time Complexity: O(2^n)
    Space Complexity: O(n)

*/
int recCombination(int n, int r)
{
    if(r == 0 || r == n)
    {
        return 1;
    }

    return recCombination(n-1, r-1) + recCombination(n-1, r);
}


int main()
{
    int n = 5;
    int r = 2;

    int res = combination(n, r);

    printf("%d\n", res);

    res = recCombination(n, r);

    printf("%d\n", res);

    return 0;
}
