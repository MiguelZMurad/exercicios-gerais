#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


int *CriaVetor(int tamanho) {
    int *vetor = (int *) malloc (tamanho * sizeof(int));

    return vetor;
}

void LeVetor(int *vetor, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}


float CalculaMedia(int *vetor, int tamanho) {
    int i;
    float media, soma = 0;

    for (i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    media = soma / (float) tamanho;

    return media;
}


void LiberaVetor(int *vetor) {

    free(vetor);
}