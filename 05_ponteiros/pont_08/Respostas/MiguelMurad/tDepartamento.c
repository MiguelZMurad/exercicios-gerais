#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>


tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ) {
    
    tDepartamento dep;

    strcpy(dep.nome, nome);
    strcpy(dep.diretor, diretor);
    strcpy(dep.curso1, curso1);
    strcpy(dep.curso2, curso2);
    strcpy(dep.curso3, curso3);

    dep.m1 = m1;
    dep.m2 = m2;
    dep.m3 = m3;

    return dep;
}


void ImprimeAtributosDepartamento(tDepartamento depto) {
    float media;
    float soma = depto.m1 + depto.m2 + depto.m3;

    media = soma / 3.0; 

    printf("\n");

    printf("Departamento: %s\n", depto.nome);
    printf("Diretor: %s\n", depto.diretor);
    printf("1o curso: %s\n", depto.curso1);
    printf("Media do 1o curso: %d\n", depto.m1);
    printf("2o curso: %s\n", depto.curso2);
    printf("Media do 2o curso: %d\n", depto.m2);
    printf("3o curso: %s\n", depto.curso3);
    printf("Media do 3o curso: %d\n", depto.m3);
    printf("Media dos cursos: %.2f\n", media);
}


void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos) {
    tDepartamento temp;
    int i, j;

    for (i = 0; i < num_deptos - 1; i++) {
        for (j = i+1; j < num_deptos; j++) {
            if (vetor_deptos[j].m1+vetor_deptos[j].m2+vetor_deptos[j].m3 > vetor_deptos[i].m1+vetor_deptos[i].m2+vetor_deptos[i].m3) {
                temp = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[j];
                vetor_deptos[j] = temp;
            }
        }
    }
}