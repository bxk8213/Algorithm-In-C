#include <stdio.h>

/*
    Expected Output: 15
    Actual Output: 
*/

// int sumOfFNaturalNumber(int n, int sum)
// {
//     if(n <= 0)
//     {
//         return sum;
//     }
//     sum = n + sum;
//     return sumOfFNaturalNumber(n - 1, sum);

// }

int sumOfFNaturalNumber(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return sumOfFNaturalNumber(n - 1) + n;

}

int main()
{
    int n = 5;
    int sum = 0;
    sum = sumOfFNaturalNumber(n);

    printf("%d\n", sum);

    return 0;
}