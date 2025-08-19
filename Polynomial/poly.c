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

int evaluate(struct Poly p){
    int sum = 0;
    int x;

    printf("Enter value of x: ");
    scanf("%d", &x);

    for(int i = 0; i < p.n; i++)
    {
        sum += p.term[i].coff * pow(x, p.term[i].exp);
    }

    return sum;
}

int evaluateMulti(struct Poly p){
    int sum = 0;
    int x;

    for(int i = 0; i < p.n; i++)
    {
        printf("Enter value of x for term %d: ", i+1);
        scanf("%d", &x);
        sum += p.term[i].coff * pow(x, p.term[i].exp);
    }

    return sum;
}

struct Poly * addPoly(struct Poly * p1, struct Poly *p2){

    struct Poly *p3;
    
    p3 = (struct Poly *) malloc(sizeof(struct Poly));

    assert(p3 != NULL);

    p3->term = (struct Terms *) malloc((p1->n + p2->n) * sizeof(struct Terms));

    int i, j, k;
    i = j = k = 0;

    while(i < p1->n && j < p2->n){

        if(p1->term[i].exp > p2->term[j].exp){
            p3->term[k++] = p1->term[i++];
        }else if(p1->term[i].exp < p2->term[j].exp){
            p3->term[k++] = p2->term[j++];
        }else{
            p3->term[k].exp = p1->term[i].exp;
            p3->term[k++].coff = p1->term[i++].coff + p2->term[j++].coff;
        }
    }

    for(; i < p1->n; i++){
        p3->term[k++] = p1->term[i];
    }

    for(; j < p2->n; j++){
        p3->term[k++] = p2->term[j];
    }

    p3->n = k;

    return p3;

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
    struct Poly *p1, *p2;
    
    p1 = (struct Poly*) malloc(sizeof(struct Poly));
    p2 = (struct Poly*) malloc(sizeof(struct Poly));

    assert(p1 != NULL); // verify memory is allocated
    assert(p2 != NULL); 


    // Create Polynomial
    create(p1);
    create(p2);


    display((*p1));
    printf("\n");
    display((*p2));

    int res;
    
    res = evaluate((*p1));

    printf("Evaluation of polynomial: %d\n", res);

    res = evaluateMulti((*p1));

    printf("Evaluation of multi-variable polynomial: %d\n", res);

    struct Poly *p3;

    p3 = addPoly(p1, p2);

    display((*p3));

    res = evaluate((*p3));

    printf("Evaluation of polynomial: %d\n", res);
}