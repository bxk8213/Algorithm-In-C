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

int recMaxNum(Node *head, Node *curr){

    int maxElement;

    if(curr->next == NULL)
        return curr->data;


    maxElement = recMaxNum(head, curr->next);

    if(maxElement < curr->data)
        return curr->data;
    
    else 
        return maxElement;
    
}

int ternaryMaxNum(Node *head, Node *curr){

    int max;

    if(curr->next == NULL)
        return curr->data;
    
    max = ternaryMaxNum(head, curr->next);

    return max > curr->data ? max : curr->data;
}

int linearSearch(Node *head, int target){

    Node *curr = head;

    while(curr != NULL && curr->data != target){
            curr = curr->next;
    }

    if(curr != NULL)
        return curr->data;
    else
        return 0;
}

/*
    Move to head approach: 
        Data that are recently searched are move to top position.
*/
Node * improvedLinearSearch(Node *head, int target){  
    
    Node *curr = head, *prev = NULL;

    while(curr != NULL){

        if(target == curr->data){
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            return head;
        }

        prev = curr;
        curr = curr->next;
        
    }

    return head;

}

Node * insert(Node *head, int position, int value){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if(position == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else if(position > 0)
    {
        Node *curr = head;

        for(int i = 0; i < position - 1 && curr != NULL; i++){
            curr = curr->next;
        }

        if(curr != NULL)
        {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    else
    {
        printf("Not valid position.");
    }
    
    return head;
    
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
    printf("Max Element: %d\n", max);

    int recMax = recMaxNum(head, curr);
    printf("Max Element: %d\n", recMax);

    int terMax = ternaryMaxNum(head, curr);
    printf("Max ter Element: %d\n", terMax);

    int data = linearSearch(head, 14);
    if(!data){
        printf("Data not found\n");
    }
    else{
        printf("Data found: %d\n", data);
    }

    // head = improvedLinearSearch(head, 16);

    display(head);

    printf("\n");
    head = insert(head, 4, 6);
    head = insert(head, 0, 7);
    head = insert(head, 8, 12);
    head = insert(head, 3, 2);


    display(head);

 
}