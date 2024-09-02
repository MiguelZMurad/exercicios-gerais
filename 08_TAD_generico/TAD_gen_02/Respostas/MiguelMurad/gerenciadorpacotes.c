#include "gerenciadorpacotes.h"
#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes {
    tPacote **pacote;
    int qtd;
};

typedef struct gerenciadorpacotes tGerenciador;

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador() {
    tGerenciador *g = (tGerenciador*) malloc (sizeof(tGerenciador));

    g->pacote = NULL;
    g->qtd = 0;

    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    geren->qtd++;

    geren->pacote = realloc (geren->pacote, geren->qtd * sizeof(tPacote*));

    geren->pacote[geren->qtd-1] = pac;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren) {
    int i;

    for (i = 0; i < geren->qtd; i++) {
        DestroiPacote(geren->pacote[i]);
    }

    free(geren->pacote);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {

    ImprimePacote(geren->pacote[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren) {
    int i;

    for (i = 0; i < geren->qtd; i++) {
        ImprimePacote(geren->pacote[i]);
    }
}
