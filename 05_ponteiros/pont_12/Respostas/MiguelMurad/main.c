#include "vetor.h"
#include <stdio.h>


int soma(int num1, int num2) {
    
    int result = num1 + num2;

    return result;
}


int multiplicacao(int num1, int num2) {
    
    int result = num1 * num2;

    return result;
}


int main () {
    Vetor vet;
    int result;

    LeVetor(&vet);

    result = AplicarOperacaoVetor(&vet, soma);

    printf("Soma: %d\n", result);

    result = AplicarOperacaoVetor(&vet, multiplicacao);

    printf("Produto: %d\n", result);

    return 0;
}