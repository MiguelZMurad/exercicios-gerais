#include "eleicao.h"
#include "eleitor.h"
#include "candidato.h"
#include <stdio.h>
#include <stdlib.h>


tEleicao InicializaEleicao() {
    int i, qtdT, qtdP = 0, qtdG = 0, pre = 0, gov = 0;

    scanf("%d", &qtdT);
    tCandidato candidato[qtdT];


    for (i = 0; i < qtdT; i++) {
        candidato[i] = LeCandidato();
        if (ObtemCargo(candidato[i]) == 'P') {
            qtdP++;
        }
        if (ObtemCargo(candidato[i]) == 'G') {
            qtdG++;
        }
    }
    i = 0;

    tEleicao eleicao;

    eleicao.totalGovernadores = qtdG;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    eleicao.totalPresidentes = qtdP;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    while (i < qtdT) {
        if (ObtemCargo(candidato[i]) == 'P') {
            eleicao.presidentes[pre] = CriaCandidato(candidato[i].nome, candidato[i].partido, candidato[i].cargo, candidato[i].id);
            pre++;
        }
        else {
            eleicao.governadores[gov] = CriaCandidato(candidato[i].nome, candidato[i].partido, candidato[i].cargo, candidato[i].id);
            gov++;
        }
        i++;
    }

    /*for (i = 0; i < eleicao.totalPresidentes; i++) {
        printf("PRES: ");

        ImprimeCandidato(eleicao.presidentes[i], 2.0);
    }
    for (i = 0; i < eleicao.totalGovernadores; i++) {
        printf("GOV: ");

        ImprimeCandidato(eleicao.governadores[i], 2.0);
    }*/

    return eleicao;
}


tEleicao RealizaEleicao(tEleicao eleicao) {
    int i, j, qtd, flagG = 0, flagP = 0;

    scanf("%d", &qtd);

    eleicao.totalEleitores = qtd;

    for (i = 0; i < eleicao.totalEleitores; i++) {
        eleicao.eleitores[i] = LeEleitor();

        if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0) {
            eleicao.votosBrancosPresidente++;
            flagP = 1;
        }
        if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0) {
            eleicao.votosBrancosGovernador++;
            flagG = 1;
        }

        for (j = 0; j < eleicao.totalEleitores; j++) {
            if (VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleicao.eleitores[i]))) {
                //printf("AQQUUUUUUUUIIIIIIIIIIII\n");
                eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                flagP = 1;
            }
        }
        for (j = 0; j < eleicao.totalEleitores; j++) {
            if (VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleicao.eleitores[i]))) {
                eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                flagG = 1;
            }
        }

        if (flagP == 0) {
            eleicao.votosNulosPresidente++;
        }
        if (flagG == 0) {
            eleicao.votosNulosGovernador++;
        }

        flagG = 0;
        flagP = 0;
    }

    /*for (i = 0; i < eleicao.totalPresidentes; i++) {
        printf("PRES: ");

        ImprimeCandidato(eleicao.presidentes[i], 2.0);
    }
    for (i = 0; i < eleicao.totalGovernadores; i++) {
        printf("GOV: ");

        ImprimeCandidato(eleicao.governadores[i], 2.0);
    }*/

    return eleicao;
}


void ImprimeResultadoEleicao(tEleicao eleicao) {
    int i, j, maxPre = 0, maxGov = 0, flagGov = 0, flagPre = 0;
    int totalDeVotosInvalidosGov = 0, totalDeVotosInvalidosPre = 0;
    int qualG, qualP;
    float percentualP, percentualG;

    if (eleicao.totalEleitores > MAX_ELEITORES) {
        printf("ELEICAO ANULADA\n");
        exit(0);
    }

    for (i = 0; i < eleicao.totalEleitores-1; i++) {
        for (j = 1; j < eleicao.totalEleitores-i; j++) {
            if(eleicao.eleitores[i].id == eleicao.eleitores[i+j].id) {
                printf("ELEICAO ANULADA\n");
                exit(0);
            }
        }
    }

    totalDeVotosInvalidosGov = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;
    totalDeVotosInvalidosPre = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;

    for (i = 0; i < eleicao.totalPresidentes; i++) {
        if (eleicao.presidentes[i].votos >= maxPre) {
            //printf("AQUIIII\n");
            maxPre = eleicao.presidentes[i].votos;
            qualP = i;
            //ImprimeCandidato(eleicao.presidentes[i], 2.0);
        }
    }

    j = 0;
    
    if (flagPre == 0) {
        for (i = 0; i < eleicao.totalPresidentes; i++) {
            if ((ObtemVotos(eleicao.presidentes[i]) == maxPre) && !EhMesmoCandidato(eleicao.presidentes[i], eleicao.presidentes[qualP])) {
                printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                flagPre = 1;
                break;
            }
        }
    }

    if (flagPre == 0) {
        if (totalDeVotosInvalidosPre > maxPre) {
            printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
            flagPre = 1;
        }
    }

    if (flagPre == 0) {
        printf("- PRESIDENTE ELEITO: ");
        percentualP = CalculaPercentualVotos(eleicao.presidentes[qualP], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.presidentes[qualP], percentualP);
    }



    for (i = 0; i < eleicao.totalGovernadores; i++) {
        if (eleicao.governadores[i].votos >= maxGov) {
            maxGov = eleicao.governadores[i].votos;
            qualG = i;
            //ImprimeCandidato(eleicao.governadores[i], 2.0);
        }
    }

    j = 0;

    if (flagGov == 0) {
        for (i = 0; i < eleicao.totalGovernadores; i++) {
            if ((ObtemVotos(eleicao.governadores[i]) == maxGov) && !EhMesmoCandidato(eleicao.governadores[i], eleicao.governadores[qualG])) {
            printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            flagGov = 1;
            break;
            }
        }
    }

    if (flagGov == 0) {
        if (totalDeVotosInvalidosGov > maxGov) {
            printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
            flagGov = 1;
        }
    }


    if (flagGov == 0) {
        printf("- GOVERNADOR ELEITO: ");
        percentualG = CalculaPercentualVotos(eleicao.governadores[qualG], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.governadores[qualG], percentualG);
    }


    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador+eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador+eleicao.votosBrancosPresidente);

}
