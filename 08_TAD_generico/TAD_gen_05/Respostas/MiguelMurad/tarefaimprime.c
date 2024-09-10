#include "tarefaimprime.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct impr {
    char *msg;
};


/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg) {
    tImpr *i = (tImpr*) malloc (sizeof(tImpr));
    i->msg = malloc (strlen(msg)+1 * sizeof(char));

    strcpy(i->msg, msg);

    return i;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp) {
    tImpr *i = (tImpr*) imp;
    printf("\n%s\n", i->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp) {
    tImpr *i = (tImpr*) imp;

    free(i->msg);
    free(i);
}