#include "pessoa.h"
#include <stdio.h>


int main () {
    int qtd, i;

    scanf("%d", &qtd);
    tPessoa pessoa[qtd];

    for (i = 0; i < qtd; i++) {
        pessoa[i] = CriaPessoa();

        LePessoa(&pessoa[i]);
    }

    AssociaFamiliasGruposPessoas(pessoa);

    for (i = 0; i < qtd; i++) {
        ImprimePessoa(&pessoa[i]);
    }

    return 0;
}