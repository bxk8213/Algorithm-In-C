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

int countingNodes(Node *head){

    int count = 0;
    Node *current;
    current = head;
    count++;

    while(current->next != NULL){

        count++;
        current = current->next;
    }

    return count;
}

int recCountNodes(Node *head, Node *curr){

    if(curr == NULL)
        return 0;
    
    return recCountNodes(head, curr->next) + 1;

}

int maxNum(Node *head){
    Node *curr = head;
    int maxElement = curr->data;

    while(curr->next != NULL){
        curr = curr->next;

        if(maxElement < curr->data){
            maxElement = curr->data;
        }
    }

    return maxElement;
}

int main(){

    int A[] = {3, 13, 5, 19, 16, 18};

    Node *head = NULL;
    // head = (Node *) malloc(sizeof(Node));

    printf("%d\n", A[0]);

    head = create(A, 6, head);

    display(head);

    printf("\nRecursively printing: \n");

    Node *curr;
    curr = head;
    recursiveDisplay(head, curr);

    int res = countingNodes(head);
    printf("\nTotal Nodes: %d\n", res);

    printf("%ld %ld\n", (long int)head, (long int)curr);

    int resu = recCountNodes(head, curr);
    printf("\nTotal Nodes: %d\n", resu);

    int max = maxNum(head);
    printf("Max Element: %d", max);

}