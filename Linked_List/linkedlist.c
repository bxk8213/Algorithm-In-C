#include <stdio.h>
#include <stdlib.h>

// Create a Node structure
typedef struct NodeLL{
    int data;
    struct NodeLL * next;
}Node;

Node * create(int A[], int n, Node *head)
{

    Node *tail, *curr;

    if(head == NULL){
        head = (Node*)malloc(sizeof(Node));
        head->data = A[0];
        head->next = NULL;
        tail = head;
    }

    for(int i = 1; i < n; i++)
    {
        curr = (Node *) malloc(sizeof(Node));
        curr->data = A[i];
        curr->next = NULL;
        tail->next = curr;
        tail = curr;
    }

    return head;

}


void display(Node *head){

    Node *curr = head;

    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void recursiveDisplay(Node *head, Node *curr){

    if(curr == NULL){
        return;
    }
    printf("%d ", curr->data);
    recursiveDisplay(head, curr->next);
}


int main(){

    int A[] = {3, 5, 6, 13, 15, 18};

    Node *head = NULL;
    // head = (Node *) malloc(sizeof(Node));

    printf("%d\n", A[0]);

    head = create(A, 6, head);

    display(head);

    printf("\nRecursively printing: \n");

    Node *curr;
    curr = head;
    recursiveDisplay(head, curr);

}