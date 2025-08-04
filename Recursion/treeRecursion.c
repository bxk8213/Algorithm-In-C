#include <stdio.h>

/*
    Tree Recursion:
        If a function has more than one recursive call.

    Expected Output:  3, 2, 1, 0, 0, 2, 1, 0, 1, 0, ...
    Actual Ouput: 3, 2, 1, 0, 0, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0, 3, 2, 1, 0, 0, 1, 0, 0, 2, 1, 0, 0, 1, 0, 0

    Time Complexity : O(2 ^ n) - Exponential
    Space Complexity: O(height of tree) - O(n)

*/

void treeRecursion(int n)
{
    if(n < 0)
    {
        return;
    }

    printf("%d, ", n);
    // 1st recursive call
    treeRecursion(n - 1);

    printf("%d, ", n);
    // 2nd recursive call
    treeRecursion(n - 1);
}

int main()
{
    int n = 3;

    treeRecursion(n);

    return 0;
}