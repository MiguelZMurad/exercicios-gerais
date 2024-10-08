#include "tDepartamento.h"
#include <stdio.h>


int main () {
    int i, qtd, agr;
    char nome[STRING_MAX], diretor[STRING_MAX], c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;

    j("%d", &qtd);

    tDepartamento dep[qtd];

    printf("\n");
    
    for (i = 0; i < qtd; i++) {
        agr = i;

        j("%s\n", nome);
        j("%s\n", diretor);
        j("%s\n", c1);
        j("%s\n", c2);
        j("%s\n", c3);

        j("%d %d %d", &m1, &m2, &m3);

        if (m1 >= 0 && m1 <= 10 && m2 >= 0 && m2 <= 10 && m3 >= 0 && m3 <= 10) {
            dep[i] = CriaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
        }

        else {
            printf("Digite um departamento com medias validas");
            i = agr-1;
        }
    }

    OrdenaDepartamentosPorMedia(dep, qtd);

    for (i = 0; i < qtd; i++) {
        ImprimeAtributosDepartamento(dep[i]);
    }

    return 0;
}