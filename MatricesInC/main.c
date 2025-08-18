#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void initLower()
{
    Matrix m;
    int x;

    printf("Enter matrix dimension: ");
    scanf("%d", &m.dimension);

    m.A = (int *)malloc((m.dimension * (m.dimension + 1) / 2) * sizeof(int));

    printf("\nEnter all elements: \n");

    for(int i = 1; i <= m.dimension; i++)
    {
        for(int j = 1; j <= m.dimension; j++)
        {
            scanf("%d", &x);
            setLower(&m, i, j, x);
        }
    }
    
    printf("\n\n");

    displayLower(m);

}



int main()
{
    // struct Matrix m;

    // m.dimension = 5;

    // set(&m, 1, 1, 6);
    // set(&m, 2, 2, 8);
    // set(&m, 3, 3, 3);
    // set(&m, 4, 4, 9);
    // set(&m, 5, 5, 7);

    // display(m);

    // int res = get(m, 3, 3);

    // printf("result: %d\n", res);

    initLower();

}
