#include <stdio.h>

/*
    Tower of Hanoi: 
        Move n disks (of variant sizes) from tower A to tower C, can use tower B

        Constraint:
            1. Can move only one disk at a time
            2. Cannot put bigger disk on top of smaller one

    Expected Output: 
    1 to 2
    1 to 3
    3 to 1
    1 to 2
    2 to 3
    2 to 1
    1 to 2

    Actual Output: Matches Expected output.

    Time Complexity: O(2^n)
    Space Complexity: O(n)
*/

void TOH(int n, int A, int B, int C)
{
    if(n > 0)
    {
        TOH(n-1, A, C, B);
        printf("%d to %d\n", A, B);
        TOH(n-1, B, A, C);
    }
}


int main()
{
    int n = 3, A = 1, B = 2, C = 3;

    TOH(n, A, B, C);
}