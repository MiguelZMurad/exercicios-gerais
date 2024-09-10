#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

/*typedef struct soma tSoma;*/

struct mult {
    float n1;
    float n2;
};


/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult *m = (tMult*) malloc (sizeof(tMult));

    m->n1 = n1;
    m->n2 = n2;
    
    return m;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult) {
    float result = 0;

    tMult *m = (tMult*) mult;

    result = m->n1 * m->n2;

    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f\n", m->n1, m->n2, result);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult) {
    free(mult);
}