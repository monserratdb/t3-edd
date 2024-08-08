#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//links de referencias de código:
//https://github.com/IIC2133-PUC/2024-1/blob/main/Ayudant%C3%ADas/10-Ayudantia-Greedy-PDinamica.pdf

static bool check_arguments(int argc, char **argv) {
  if (argc != 3) {
    printf("Modo de uso: %s INPUT OUTPUT\n", argv[0]);
    printf("Donde:\n");
    printf("\tINPUT es la ruta del archivo de input\n");
    printf("\tOUTPUT es la ruta del archivo de output\n");
    exit(1);
  }
  return true;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv) {
    check_arguments(argc, argv);

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    int CANT_PLANETAS;
    fscanf(input_file, "%d", &CANT_PLANETAS);

    int *POSICIONES_PLANETAS = (int *)malloc(CANT_PLANETAS * sizeof(int));
    //leer las posiciones p_i de los planetas y alocarlos en un array 
    for (int q = 0; q < CANT_PLANETAS; q++) {
        fscanf(input_file, "%d", &POSICIONES_PLANETAS[q]);
    }

    // Leer el Rango
    int RANGO;
    fscanf(input_file, "%d", &RANGO);

    //ordenar las posiciones de los planetas
    qsort(POSICIONES_PLANETAS, CANT_PLANETAS, sizeof(int), compare);

    int naves = 0;
    int i = 0;
    while (i < CANT_PLANETAS) {
        //encuentr la posición más a la derecha donde se puede colocar una nave
        int posicion_centro = POSICIONES_PLANETAS[i] + RANGO;
        naves++;
        
        //avanza hasta cubrir todos los planetas dentro del rango de la nave
        while (i < CANT_PLANETAS && POSICIONES_PLANETAS[i] <= posicion_centro + RANGO) {
            i++;
        }
    }

    fprintf(output_file, "%d\n", naves);

    /* Cerrar archivos */
    fclose(input_file);
    fclose(output_file);
    free(POSICIONES_PLANETAS);

    return 0;
}
