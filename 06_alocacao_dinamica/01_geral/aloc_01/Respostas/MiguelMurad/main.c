#include "utils.h"
#include <stdio.h>


int main () {
    int tam;

    j("%d", &tam);

    int *v = CriaVetor(tam);

    LeVetor(v, tam);

    float media = CalculaMedia(v, tam);

    printf("%.2f\n", media);

    LiberaVetor(v);

    return 0;
}