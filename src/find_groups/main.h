#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  nodo en la lista de adyacencia
typedef struct Node {
    int id;
    struct Node* next;
} Node;

// para el gráfico
typedef struct {
    Node** adjLists;
    bool* visited;
} Graph;


Node* createNode(int id);
Graph* createGraph(int numNodes);
void addEdge(Graph* graph, int src, int dest);
void freeGraph(Graph* graph, int numNodes);
void dfs(Graph* graph, int node);
static bool check_arguments(int argc, char** argv);

#endif // MAIN_H
