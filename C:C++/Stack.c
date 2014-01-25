#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Stack
{
    Node *top;
}Stack;

Stack *createStack()
{
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int pop(Stack *s)
{
    if (empty(s))
        printf("Stack is Empty\n");
    else {
        Node *temp = s->top;
        int num = temp->data;
        s->top = temp->next;
        free(temp);
        return num;
    }
}

void push(Stack *s, int element)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = element;
    temp->next = s->top;
    s->top = temp;
}

bool empty(Stack *s) {
    
    return (s->top == NULL);
}