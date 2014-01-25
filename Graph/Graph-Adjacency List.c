#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode
{
    int key;
    struct AdjListNode *next;
}AdjListNode;

typedef struct AdjList
{
    AdjListNode *head;
}AdjList;

typedef struct Graph
{
    int numVertices;
    AdjList *array;
}Graph;

AdjListNode *newAdjListNode(int key)
{
    AdjListNode newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int V)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertices = V;
    g->array = (AdjList *)malloc(sizeof(V * sizeof(AdjList)));
    for (int i=0; i<V; i++)
        g->array[i].head = NULL;
    return g;    
}

void addEdge(Graph *graph, int src, int dest)
{
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


