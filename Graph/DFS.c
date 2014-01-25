#include <stdio.h>
#include <stdlib.h>

void DFS(Graph *g, int presentVertex, int *visited)
{
    Stack *S = createStack(maxVertices)
    push(S, presentVertex);
    while (S->size)
    {
        u = pop(S);
        AdjListNode *newNode;
        newNode = g->array[u].head;
        if (!visited[u])
        {
            visited[u] = 1;
            for (;newNode != NULL; ) {
                push(S, newNode->key);
                newNode = newNode->next;                
            }            
        }
    }
}