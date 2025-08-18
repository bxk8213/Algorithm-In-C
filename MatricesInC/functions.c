#include <stdio.h>
#include "functions.h"

/*
    Diagonal Matrix
*/
void setDiagonal(struct Matrix *m, int i, int j, int x)
{
    if(i == j)
    {
        m->A[i-1] = x;
    }
}

int getDiagonal(struct Matrix m, int i, int j)
{
    if(i == j)
    {
        return m.A[i-1];
    }
    else
    {
        return 0;
    }
}

void displayDiagonal(struct Matrix m)
{
    int i, j;
    for(i = 0; i < m.dimension; i++)
    {
        for(j = 0; j < m.dimension; j++)
        {
            if(i == j)
            {
                printf("%d ", m.A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

/*
    Lower Triangular Matrix
    Written is Row Major.

    For Column Major replace the formula for index.
    index = n * (j-1) + ((j-2)*(j-1))/2 + (i-j)
*/

void setLower(Matrix *m, int i, int j, int x)
{
    int index;

    if(i >= j)
    {
       index = ((i * (i - 1)) / 2) + (j - 1);
       m->A[index] = x;
    }
}

int getLower(Matrix m, int i, int j)
{
    int index;
    if(i >= j)
    {
        index = ((i * (i - 1)) / 2) + (j - 1);
        return m.A[index];
    }
    else
    {
        return 0;
    }
}

void displayLower(Matrix m)
{
    int i, j, index;

    for(i = 1; i <= m.dimension; i++)
    {
        for(j = 1; j <= m.dimension; j++)
        {
            if(i >= j)
            {
                index = ((i * (i - 1)) / 2) + (j - 1);
                printf("%d ", m.A[index]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

