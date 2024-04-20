#include <stdio.h>
#include "aluno.h"
#include "string.h"

int main () {
    int qtd, i, j;

    scanf("%d", &qtd);

    tAluno aluno[qtd];
    tAluno temp;

    for (i = 0; i < qtd; i++) {

        aluno[i] = LeAluno();
    }

    for (i = 0; i < qtd - 1; i++) {
        for (j = 0; j < qtd - i - 1; j++) {
            if (ComparaMatricula(aluno[j], aluno[j+1]) == 1) {
                temp = aluno[j];
                aluno[j] = aluno[j+1];
                aluno[j+1] = temp;
            }
        }
    }

    for (i = 0; i < qtd; i++) {

        if (VerificaAprovacao(aluno[i])) {
            ImprimeAluno(aluno[i]);
        }
    }

    return 0;
}