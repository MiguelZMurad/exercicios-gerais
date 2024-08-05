#include "vetor.h"
#include <stdio.h>


void LeDadosParaVetor(int * vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        scanf("%d", &vet[i]);
    }
}


void ImprimeDadosDoVetor(int * n, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
}


void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int min = vet[0];

    for (int i = 0; i < tam; i++) {
        if (vet[i] < min) {
            min = vet[i];
        }
    }

    if (min < *paraTrocar) {
        *paraTrocar = min; 
    }
}


void OrdeneCrescente(int * vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int minIndex = i;
        int minValue = vet[i];

        TrocaSeAcharMenor(vet + i, tam - i, &minValue);

        for (int j = i; j < tam; j++) {
            if (vet[j] == minValue) {
                minIndex = j;
                break;
            }
        }

        if (minIndex != i) {
            int temp = vet[i];
            vet[i] = vet[minIndex];
            vet[minIndex] = temp;
        }
    }
}