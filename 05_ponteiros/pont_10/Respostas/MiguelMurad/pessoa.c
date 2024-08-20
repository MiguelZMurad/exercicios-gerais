#include "pessoa.h"
#include <stdio.h>
#include <string.h>


tPessoa CriaPessoa() {
    tPessoa pessoa;

    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;

    pessoa.nome[0] = '\0';

    return pessoa;
}


void LePessoa(tPessoa *pessoa) {

    scanf("\n%[^\n]\n", pessoa->nome);
    //printf("%s\n", pessoa->nome);
}


int VerificaSeTemPaisPessoa(tPessoa *pessoa) {

    if (pessoa->pai == NULL && pessoa->mae == NULL) {
        return 0;
    }

    return 1;
}


void ImprimePessoa(tPessoa *pessoa) {

    if (VerificaSeTemPaisPessoa(pessoa)) {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        
        if (pessoa->pai == NULL) {
            printf("PAI: NAO INFORMADO\n");
        }
        else {
            //printf("PAI: %d\n", pessoa->pai);
            printf("PAI: %s\n", pessoa->pai->nome);
        }

        if (pessoa->mae == NULL) {
            printf("MAE: NAO INFORMADO\n");
        }
        else {
            //printf("MAE: %d\n", pessoa->mae);
            printf("MAE: %s\n", pessoa->mae->nome);
        }

        if (pessoa->irmao == NULL) {
            printf("IRMAO: NAO INFORMADO\n");
        }
        else {
            //printf("MAE: %d\n", pessoa->mae);
            printf("IRMAO: %s\n", pessoa->irmao->nome);
        }
        printf("\n");
    }
}


int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2) {
    //printf("OLS\n");
    if (((pessoa1->pai == pessoa2->pai) && (pessoa1->mae == pessoa2->mae))) {
        //printf("AQUI\n");
        return 1;
    }

    return 0;
}


void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas) {
    int qtd, mae, pai, filho;
    int i, j;

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        getchar();
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho);
        //printf("mae: %d, pai: %d, filho: %d\n", mae, pai, filho);
        if (pai != -1) {
            pessoas[filho].pai = &pessoas[pai];
        }
        if (mae != -1) {
            pessoas[filho].mae = &pessoas[mae];
        }
    }

    for (i = 0; i < numPessoas-1; i++) {
        for (j = i+1; j < numPessoas; j++) {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])) {
                //printf("AQUI\n");
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}