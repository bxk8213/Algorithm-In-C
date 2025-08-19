#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

void display(struct Poly p){


    assert(p.n < 10); // verify n is less than 10.

    for(int i = 0; i < p.n; i++)
    {
        printf("%dX^%d + ", p.term[i].coff, p.term[i].exp);
    }
}


int main()
{
    struct Poly *p1;
    
    p1 = (struct Poly*) malloc(sizeof(struct Poly));

    assert(p1 != NULL); // verify memory is allocated

    create(p1);

    display((*p1));
}