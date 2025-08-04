#include <stdio.h>

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/
int power(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }

    return m * power(m, n - 1);
}

int powerV2(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n % 2 == 0)
    {
        return powerV2(m * m, n/2);
    }
    else
    {
        return m * powerV2(m * m, (n - 1) / 2);
    }

}

int main(){
    int m = 3;
    int n = 10;

    int r = power(m, n);

    printf("%d\n", r);

    r = powerV2(m, n);

    printf("%d\n", r);

    return 0;
}