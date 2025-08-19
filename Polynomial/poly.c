#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct Terms{
    int coff;
    int exp;
};

struct Poly{
    int n; // # non-zero elements
    struct Terms *term;
};

void create(struct Poly *p){
    
    printf("Enter number of terms: ");
    scanf("%d", &p->n);

    p->term = (struct Terms*) malloc(p->n * sizeof(struct Terms));

    assert(p->term != NULL); // verify memory is allocated.

    printf("Enter all terms, coefficient first and exponent: ");
    for(int i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->term[i].coff, &p->term[i].exp);
    }
}

int evaluate(struct Poly p)
{
    int sum = 0;
    int x;

    printf("Enter value of x: ");
    scanf("%d", &x);

    for(int i = 0; i < p.n; i++)
    {
        printf("sum: %d\n", sum);
        sum += p.term[i].coff * pow(x, p.term[i].exp);
        printf("sum: %d\n", sum);
    }

    return sum;
}

void display(struct Poly p){

    assert(p.n < 10); // verify n is less than 10.

    int i;
    for(i = 0; i < p.n - 1; i++)
    {
        printf("%dX^%d + ", p.term[i].coff, p.term[i].exp);
    }
    printf("%dX^%d\n", p.term[i].coff, p.term[i].exp);
}


int main()
{
    struct Poly *p1;
    
    p1 = (struct Poly*) malloc(sizeof(struct Poly));

    assert(p1 != NULL); // verify memory is allocated

    create(p1);

    display((*p1));

    int res = evaluate((*p1));

    printf("Evaluation of polynomial: %d\n", res);
}