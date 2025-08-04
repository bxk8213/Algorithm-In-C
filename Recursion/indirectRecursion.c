#include <stdio.h>

/*
    Indirect Recursion: 

        If the function call chaining forms a cycle.
        A B C 
        A -> B -> C -> A 

        Expected Ouput: 20, 10, 19, 9, 17, 7, 13, 3, 5
        Actual Output: 20, 10, 19, 9, 17, 7, 13, 3, 5

        Time Complexity: O(log n)
        Space Complexity: O(n)
        
*/

void funB(int n);

void funA(int n)
{
    if(n < 0)
    {
        return;
    }
    printf("%d, ", n);
    funB(n - 10);
    
}

void funB(int n)
{
    if(n < 0)
    {
        return;
    }
    printf("%d, ", n);
    funA((n * 2) - 1);   
}


int main()
{
    int n = 20;

    funA(n);
}