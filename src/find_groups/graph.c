#include "main.h"

Node* createNode(int id) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjLists = (Node**)malloc(numNodes * sizeof(Node*));
    graph->visited = (bool*)malloc(numNodes * sizeof(bool));
    for (int i = 0; i < numNodes; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void freeGraph(Graph* graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        Node* node = graph->adjLists[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

void dfs(Graph* graph, int node) {
    graph->visited[node] = true;
    Node* adjList = graph->adjLists[node];
    while (adjList) {
        int connectedNode = adjList->id;
        if (!graph->visited[connectedNode]) {
            dfs(graph, connectedNode);
        }
        adjList = adjList->next;
    }
}
