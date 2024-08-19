#include "utils_char2.h"
#include <stdio.h>
#include <stdlib.h>


char *CriaVetorTamPadrao() {
    int i;

    char *v = (char *) malloc (TAM_PADRAO+1 * sizeof(char));

    for (i = 0; i < TAM_PADRAO; i++) {
        v[i] = '_';
    }

    v[TAM_PADRAO] = '\0';

    //printf("CRIA: %s\n", v);

    return v;
}


char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo) {
    int i;

    vetor = (char *) realloc (vetor, tamanhoantigo+TAM_PADRAO+1 * sizeof(char));

    for (i = tamanhoantigo; i < tamanhoantigo+TAM_PADRAO; i++) {
        vetor[i] = '_'; 
    }

    vetor[tamanhoantigo+TAM_PADRAO] = '\0';

    return vetor;
}


char *LeVetor(char *vetor, int *tamanho) {
    char temp;
    int index = 0;
    
    while (scanf("%c", &temp) && temp != '\n') { // Lê caractere por caractere até encontrar '\n'
        if (index >= *tamanho - 1) { // Se o vetor estiver cheio, aumente o tamanho
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[index++] = temp;
    }
    vetor[*tamanho] = '\0'; // Termina a string com '\0'

    //printf("LE: %s\n", vetor);
    
    return vetor;
}


void ImprimeString(char *vetor) {

    printf("%s", vetor);
}


void LiberaVetor(char *vetor) {

    free(vetor);
}