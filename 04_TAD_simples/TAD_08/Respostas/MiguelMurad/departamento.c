#include "departamento.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor) {
    tDepartamento departamento;

    strcpy(departamento.c1, c1);

    strcpy(departamento.c2, c2);
    
    strcpy(departamento.c3, c3);
    
    strcpy(departamento.nome, nome);

    strcpy(departamento.diretor, diretor);

    departamento.m1 = m1;

    departamento.m2 = m2;

    departamento.m3 = m3;

    departamento.media_geral = calculaMediaGeralDepartamento(departamento);
    
    return departamento;
}


void imprimeAtributosDepartamento (tDepartamento depto) {

    printf("ATRIBUTOS:\n");

    printf("departamento => %s\n", depto.nome);

    printf("diretor => %s\n", depto.diretor);

    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);

    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);

    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);

    printf("media geral => %.2f\n", depto.media_geral);

    printf("desvio padrao => %.2f\n\n", calculaDesvioPadraoDepartamento(depto));
}


int validaMediaDepartamento (int media) {

    if (media > 10 || media < 0) {
        return 0;
    }

    return 1;
}


double calculaDesvioPadraoDepartamento(tDepartamento depto) {
    double desvio;

    desvio = sqrt((((depto.m1 - depto.media_geral)*(depto.m1 - depto.media_geral)) + ((depto.m2 - depto.media_geral)*(depto.m2 - depto.media_geral)) + ((depto.m3 - depto.media_geral)*(depto.m3 - depto.media_geral))) / 3.0);

    return desvio;
}


double calculaMediaGeralDepartamento(tDepartamento depto) {
    double media;

    media = ((depto.m1 + depto.m2 + depto.m3) / 3.0);

    return media;
}


void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
    int i, j;
    tDepartamento temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            
            if (d[j].media_geral < d[j+1].media_geral) {
                
                temp = d[j]; 
                d[j] = d[j+1];
                d[j+1] = temp;
            }
        }
    }
}