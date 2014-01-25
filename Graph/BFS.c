/*
    This algorithm uses Queue to manage the vertices.
*/

#include <stdio.h>
#include <stdlib.h>

void BFS(Graph *g, int presentVertex, int *visited)
{
    visited[presentVertex] = 1;
    Queue *Q = createQueue(maxVertices);
    Enqueue(Q, presentVertex);
    while (Q->size)
    {
        presentVertex = Front(Q);
        Dequeue(Q);
        int k;
        AdjListNode *newNode;
        newNode = g->array[presentVertex].head;
        for(k = newNode->key;;)
        {
            if(!visited[k])
            {
                visited[k] = 1;
                Enqueue(Q, k);                
            }
            newNode = newNode->next;
            if (newNode != NULL)
                k = newNode->key;
            else
                break;
        }        
    }
}















