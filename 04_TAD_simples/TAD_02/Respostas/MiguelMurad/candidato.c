#include "candidato.h"
#include <stdio.h>
#include <string.h>


tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id) {
    tCandidato candidato;

    strcpy(candidato.nome, nome);
    
    strcpy(candidato.partido, partido);

    candidato.cargo = cargo;

    candidato.id = id;

    candidato.votos = 0;

    return candidato;
}


tCandidato LeCandidato() {
    char nome[50], partido[50], cargo;
    int id;
    tCandidato candidato;

    scanf("\n%[^,], %[^,], %c, %d\n", nome, partido, &cargo, &id);

    candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}


int VerificaIdCandidato(tCandidato candidato, int id) {

    if (candidato.id == id) {
        return 1;
    }

    return 0;
}


int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2) {
    
    if (!strcmp(candidato1.nome, candidato2.nome)) { 
        if (!strcmp(candidato1.partido, candidato2.partido)) {
            if (candidato1.cargo == candidato2.cargo) {
                if (candidato1.id == candidato2.id) {
                    return 1;
                }
            }
        }
    }

    return 0;
}


char ObtemCargo(tCandidato candidato) {

    return candidato.cargo;
}


tCandidato IncrementaVotoCandidato(tCandidato candidato) {

    candidato.votos++;

    return candidato;
}


int ObtemVotos(tCandidato candidato) {

    return candidato.votos;
}


float CalculaPercentualVotos(tCandidato candidato, int totalVotos) {
    float percentual;
    float totalVotos2;

    totalVotos2 = totalVotos;
    
    percentual = (candidato.votos*100) / totalVotos2;

    return percentual;
}


void ImprimeCandidato (tCandidato candidato, float percentualVotos) {

    printf ("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
