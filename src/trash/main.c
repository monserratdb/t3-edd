#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//links de referencias de código:
//https://medium.com/@fabiola.barajas20/soluci%C3%B3n-de-un-problema-tipo-mochila-utilizando-programaci%C3%B3n-din%C3%A1mica-52e0a637bff0
//https://github.com/IIC2133-PUC/2024-1/blob/main/Ayudant%C3%ADas/10%2B1-Ayudantia-Comparacion%20Estrategias%20Algor%C3%ADtmicas.pdf

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

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(int argc, char **argv) {
    check_arguments(argc, argv);

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    int NUM_BASURALES;
    fscanf(input_file, "%d", &NUM_BASURALES);

    int *basurales = (int *)malloc(NUM_BASURALES * sizeof(int));
    for (int q = 0; q < NUM_BASURALES; q++) {
        fscanf(input_file, "%d", &basurales[q]);
    }
  
    int NUM_A_SUMAR;
    fscanf(input_file, "%d", &NUM_A_SUMAR);

    int *dp = (int *)malloc((NUM_A_SUMAR + 1) * sizeof(int));
    for (int i = 0; i <= NUM_A_SUMAR; i++) {
        dp[i] = NUM_A_SUMAR + 1;  
    }
    dp[0] = 0;

    for (int i = 0; i <= NUM_A_SUMAR; i++) {
        for (int j = 0; j < NUM_BASURALES; j++) {
            if (i >= basurales[j]) {
                dp[i] = min(dp[i], dp[i - basurales[j]] + 1);
            }
        }
    }

    if (dp[NUM_A_SUMAR] > NUM_A_SUMAR) {
        fprintf(output_file, "-1");
    } else {
        fprintf(output_file, "%d", dp[NUM_A_SUMAR]);
    }

    /* Cerrar archivos */
    fclose(input_file);
    fclose(output_file);
    free(basurales);
    free(dp);

    return 0;
}
