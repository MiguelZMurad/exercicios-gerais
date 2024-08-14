#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


int **CriaMatriz(int linhas, int colunas) {
    int i;

    int **matriz = (int **) malloc (linhas * sizeof(int *));

    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc (colunas * sizeof(int *));
    }

    return matriz;
}


void LiberaMatriz(int **matriz, int linhas) {
    int i;

    for (i = 0; i < linhas; i++) {

        free(matriz[i]);
    }

    free(matriz);
}


void LeMatriz(int **matriz, int linhas, int colunas) {
    int i, j;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}


void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas) {
    int i, j;

    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}