#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *CriaVetor(int tamanho) {
    int i;

    char *vetor = (char *) malloc (tamanho * sizeof(char));

    for (i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }

    return vetor;
}


void LeVetor(char *vetor, int tamanho) {
    int i;
    char c;

    for (i = 0; i < tamanho; i++) {
        scanf("%c", &c);

        if (c != '\n') {
            vetor[i] = c;
        }

        if (c == '\n') {
            break;
        }
    }

    printf("AGORA:");
    for (i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }
}


void ImprimeString(char *vetor, int tamanho) {
    int i;

    /*for (i = 0; i < tamanho; i++) {
        printf("_");
    }

    printf("\n");*/

    for (i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }
}


void LiberaVetor(char *vetor) {

    free(vetor);
}