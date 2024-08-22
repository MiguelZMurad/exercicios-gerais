#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao() {
    int qtd, i;

    tEleicao *eleicao = (tEleicao*) malloc (sizeof(tEleicao));

    eleicao->presidentes = NULL;
    eleicao->totalPresidentes = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosPresidente = 0;

    eleicao->governadores = NULL;
    eleicao->totalGovernadores = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosGovernador = 0;

    eleicao->eleitores = NULL;
    eleicao->totalEleitores = 0;

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++) {
        
        tCandidato *cand = CriaCandidato();
        LeCandidato(cand);

        if (ObtemCargo(cand) == 'P') {
            eleicao->totalPresidentes++;
            eleicao->presidentes = realloc (eleicao->presidentes, eleicao->totalPresidentes * sizeof(tCandidato*));
            eleicao->presidentes[eleicao->totalPresidentes-1] = cand;
        }

        if (ObtemCargo(cand) == 'G') {
            eleicao->totalGovernadores++;
            eleicao->governadores = realloc (eleicao->governadores, eleicao->totalGovernadores * sizeof(tCandidato*));
            eleicao->governadores[eleicao->totalGovernadores-1] = cand;
        }

        ApagaCandidato(cand);
    }

    return eleicao;    
}


void ApagaEleicao(tEleicao* eleicao) {
    int i;

    for (i = 0; i < eleicao->totalPresidentes; i++) {
        ApagaCandidato(eleicao->presidentes[i]);
    }

    for (i = 0; i < eleicao->totalGovernadores; i++) {
        ApagaCandidato(eleicao->governadores[i]);
    }   

    free(eleicao->presidentes);
    free(eleicao->governadores);

    for (i = 0; i < eleicao->totalEleitores; i++) {
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);

    free(eleicao);   
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao) {
    int qtd, i, j, x, g = 0, p = 0;
    int flag = 0;

    scanf("%d", &qtd);

     eleicao->totalEleitores = qtd;   

    eleicao->eleitores = (tEleitor**) malloc (qtd * sizeof(tEleitor*));

    for (i = 0; i < qtd; i++) {
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);

        /*for (j = 0; j < i; j++) {
            if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }*/

        if (ObtemVotoPresidente(eleicao->eleitores[i]) == 0) {
            eleicao->votosBrancosPresidente++;
        }
        else {
            for (x = 0; x < eleicao->totalPresidentes; x++) {
                if (VerificaIdCandidato(eleicao->presidentes[x], eleicao->eleitores[i]->votoP)) {
                    eleicao->presidentes[x]->votos++;
                    flag = 1;
                    //printf("ID: %d\n", eleicao->presidentes[x]->id);
                }
            }
            if (flag == 0) {
                eleicao->votosNulosPresidente++;
            }
            flag = 0;
        }
        
        flag = 0;

        if (ObtemVotoGovernador(eleicao->eleitores[i]) == 0) {
            eleicao->votosBrancosGovernador++;
        }
        else {
            for (x = 0; x < eleicao->totalGovernadores; x++) {
                if (VerificaIdCandidato(eleicao->governadores[x], eleicao->eleitores[i]->votoG)) {
                    eleicao->governadores[x]->votos++;
                    //printf("CADA: %d\n", eleicao->governadores[x]->id);
                    //printf("\nAQUI\n");
                    flag = 1;
                }
            }
            if (flag == 0) {
                eleicao->votosNulosGovernador++;
            }
            flag = 0;
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao) {
    int i, j, qual = 0, votos = 0;
    int totalVotos = 0;
    int flag = 0;
    float percentual = 0;

    //printf("GOV: %d\n PRE: %d\n", eleicao->votosNulosGovernador, eleicao->votosNulosPresidente);
    //printf("TOT EL: %d\n", eleicao->totalEleitores);

    for (i = 0; i < eleicao->totalEleitores; i++) {
        for (j = 0; j < i; j++) {
            if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    /*for (i = 0; i < eleicao->totalEleitores; i++) {
        printf("ID: %d\n", eleicao->eleitores[i]);
    }*/


    for (i = 0; i < eleicao->totalPresidentes; i++) {

        totalVotos += ObtemVotos(eleicao->presidentes[i]);

        if (eleicao->presidentes[i]->votos > votos) {
            votos = eleicao->presidentes[i]->votos;
            qual = i;
        }
    }   
 
    for (i = 0; i < eleicao->totalPresidentes; i++) {
        if (eleicao->presidentes[qual]->votos == eleicao->presidentes[i]->votos) {
            flag++;
        }
    }

    totalVotos += eleicao->votosBrancosPresidente+eleicao->votosNulosPresidente;

    percentual = CalculaPercentualVotos(eleicao->presidentes[qual], totalVotos);

    printf("- PRESIDENTE ELEITO: ");

    if (flag > 1) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else {
        if (((eleicao->votosBrancosPresidente+eleicao->votosNulosPresidente) > eleicao->presidentes[qual]->votos)) {
            printf("SEM DECISAO\n");
        }
        else {
            ImprimeCandidato(eleicao->presidentes[qual], percentual);
        }
    }

    //printf("TOTAL P: %d\n", totalVotos);

    totalVotos = 0;
    qual = 0;
    percentual = 0;
    votos = 0;
    flag = 0;

    //printf("QTD G: %d\n", eleicao->totalGovernadores);
    
    for (i = 0; i < eleicao->totalGovernadores; i++) {
        //printf("CADA: %d\n", eleicao->governadores[i]->votos);
        totalVotos += ObtemVotos(eleicao->governadores[i]);
        //printf("TOTAL: %d\n", totalVotos);

        if (eleicao->governadores[i]->votos > votos) {
            //printf("ID: %d\n", eleicao->governadores[i]);
            votos = eleicao->governadores[i]->votos;
            qual = i;
        }
    }

    for (i = 0; i < eleicao->totalGovernadores; i++) {
        if (eleicao->governadores[qual]->votos == eleicao->governadores[i]->votos) {
            flag++;
        }
    }

    //printf("FLAG: %d\n", flag);

    /*printf("TOTAL:%d\n", totalVotos);
    for(j = 0; j < eleicao->totalGovernadores; j++) {
        printf("CADA: %d\n", eleicao->governadores[j]->votos);
    }*/

    totalVotos += eleicao->votosBrancosGovernador+eleicao->votosNulosGovernador;

    percentual = CalculaPercentualVotos(eleicao->governadores[qual], totalVotos);

    printf("- GOVERNADOR ELEITO: ");

    if (flag > 1) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else {
        if (((eleicao->votosBrancosGovernador+eleicao->votosNulosGovernador) > eleicao->governadores[qual]->votos)) {
            printf("SEM DECISAO\n");
        }
        else {
            ImprimeCandidato(eleicao->governadores[qual], percentual);
        }
    }
    printf("- NULOS E BRANCOS: %d, %d", eleicao->votosNulosGovernador+eleicao->votosNulosPresidente, eleicao->votosBrancosGovernador+eleicao->votosBrancosPresidente);

    ApagaEleicao(eleicao);
}
