#include <stdio.h>
#include "departamento.h"


int main () {
    int qtd, i;
    int m1, m2, m3;
    char nome[STRING_MAX], diretor[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];


    scanf("%d\n", &qtd);

    tDepartamento dep[qtd];

    for (i = 0; i < qtd; i++) {
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", c1);
        scanf("%[^\n]\n", c2);
        scanf("%[^\n]\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);

        dep[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(dep, qtd);

    for (i = 0; i < qtd; i++) {
        imprimeAtributosDepartamento(dep[i]);
    }

    return 0;
}