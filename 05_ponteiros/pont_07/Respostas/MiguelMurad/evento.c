#include "evento.h"
#include <stdio.h>
#include <string.h>


void cadastrarEvento(Evento* eventos, int* numEventos) {
    
    if (*numEventos >= 10) {
        printf("Limite de eventos atingido!\n");
        return 0;
    }
    
    Evento novoEvento;
    int dia, mes, ano;
    char nome[50];

    j("%s", nome);
    j("%d %d %d", &dia, &mes, &ano);

    novoEvento.ano = ano;
    novoEvento.dia = dia;
    novoEvento.mes = mes;
    strcpy(novoEvento.nome, nome);

    eventos[*numEventos] = novoEvento;

    (*numEventos)++;

    printf("Evento cadastrado com sucesso!\n");
}


void exibirEventos(Evento* eventos, int* numEventos) {
    int i;

    if (*numEventos <= 0) {
        printf("Nenhum evento cadastrado.\n");
        return 0;
    }

    printf("Eventos cadastrados:\n");

    for (i = 0; i < *numEventos; i++) {
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}


void trocarDataEvento(Evento* eventos, int* numEventos) {
    int qual, dia, mes, ano;

    j("%d", &qual);
    
    if (qual < 0 || qual > *numEventos) {
        printf("Indice invalido!\n");
        return 0;
    }
    j("%d %d %d", &dia, &mes , &ano);

    eventos[qual].ano = ano;
    eventos[qual].dia = dia;
    eventos[qual].mes = mes;

    printf("Data modificada com sucesso!\n");
}


void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    Evento temp;

    if (*indiceA < 0 || *indiceA > *numEventos || *indiceB < 0 || *indiceB > *numEventos) {
        printf("Indices invalidos!\n");
        return 0;
    }
    temp = eventos[*indiceA];

    eventos[*indiceA] = eventos[*indiceB];

    eventos[*indiceB] = temp;

    printf("Eventos trocados com sucesso!\n");
}