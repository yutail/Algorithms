#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Queue
{
    Node *top;
    Node *tail;
}Queue;

Queue *createQueue()
{
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));
    Q->top = NULL;
    Q->tail = NULL;
    return Q;
}

int Dequeue(Queue *Q)
{
    if (empty(Q))
        printf("Queue is Empty\n");  
    else
    {
        Node *temp = malloc(sizeof(Node));
        temp = Q->top;
        int num = temp->data;
        Q->top = temp->next;
        free(temp);
        Q->front++;
        return num;
    }    
}

void Enqueue(Queue *Q, int element)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = element;
    temp->next = NULL;
    Q->tail->next = temp;
    Q->tail = temp;    
}

int Front(Queue *Q)
{
    if (empty(Q))
        printf("Queue is Empty\n");
    else
        return Q->elements[Q->head];
}

bool empty(Queue *Q) {
    
    return (Q->top == NULL);
}














