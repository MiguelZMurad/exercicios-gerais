#include "utils_char.h"
#include <stdio.h>


int main () {
    int qtd;

    scanf("%d", &qtd);

    char *vet = CriaVetor(qtd);

    LeVetor(vet, qtd);

    ImprimeString(vet, qtd);

    LiberaVetor(vet);

    return 0;
}