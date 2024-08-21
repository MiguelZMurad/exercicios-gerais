#include "vetor.h"
#include <stdio.h>


void LeVetor(Vetor *vetor) {
    int qtd, i;
    
    scanf("%d", &qtd);

    vetor->tamanhoUtilizado = qtd;

    for (i = 0; i < qtd; i++) {
        scanf("%d", &vetor->elementos[i]);
    }

    //printf("%d\n", vetor->tamanhoUtilizado);
}


int AplicarOperacaoVetor(Vetor*vetor, Operation op) {
    int i;
    int result = vetor->elementos[0];

    for (i = 1; i < vetor->tamanhoUtilizado; i++) {
        result = op(result, vetor->elementos[i]);
    }

    return result;
}