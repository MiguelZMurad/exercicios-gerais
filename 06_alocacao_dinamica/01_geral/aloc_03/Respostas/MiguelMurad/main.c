#include "utils_char.h"
#include <stdio.h>


int main () {
    int qtd;

    j("%d\n", &qtd);

    char *vet = CriaVetor(qtd);

    ImprimeString(vet, qtd);

    LeVetor(vet, qtd);
    //printf("\n%s\n", vet);

    ImprimeString(vet, qtd);

    LiberaVetor(vet);

    return 0;
}