#include "main.h"

//links de referencias de código:
//https://github.com/IIC2133-PUC/2024-1/blob/main/Clases/Secci%C3%B3n%201/class21%20-%20DFS%20y%20aplicaciones.pdf


static bool check_arguments(int argc, char** argv) {
    if (argc != 3) {
        printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
        printf("Donde:\n");
        printf("\tINPUT es la ruta del archivo de input\n");
        printf("\tOUTPUT es la ruta del archivo de output\n");
        exit(1);
    }
    return true;
}

int main(int argc, char** argv) {
    check_arguments(argc, argv);

    FILE* input_file = fopen(argv[1], "r");
    FILE* output_file = fopen(argv[2], "w");

    int NODOS_GRAFO;
    fscanf(input_file, "%d", &NODOS_GRAFO);

    int NUM_ARISTAS;
    fscanf(input_file, "%d", &NUM_ARISTAS);

    Graph* graph = createGraph(NODOS_GRAFO);

    for (int q = 0; q < NUM_ARISTAS; q++) {
        int nodo1, nodo2;
        fscanf(input_file, "%d %d", &nodo1, &nodo2);
        addEdge(graph, nodo1, nodo2);
    }

    int count = 0;
    for (int i = 0; i < NODOS_GRAFO; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i);
            count++;
        }
    }

    fprintf(output_file, "%d\n", count);

    fclose(input_file);
    fclose(output_file);
    freeGraph(graph, NODOS_GRAFO);

    return 0;
}
