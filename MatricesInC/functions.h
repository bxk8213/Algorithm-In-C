#ifndef MATRICES
#define MATRICES

struct Matrix{
    int A[10];
    int dimension;
};

typedef struct Matrices{
    int *A;
    int dimension;
}Matrix;

void setDiagonal(struct Matrix *m, int i, int j, int x);
int getDiagonal(struct Matrix m, int i, int j);
void displayDiagonal(struct Matrix m);

void setLower(Matrix *m, int i, int j, int x);
int getLower(Matrix m, int i, int j);
void displayLower(Matrix m);


#endif