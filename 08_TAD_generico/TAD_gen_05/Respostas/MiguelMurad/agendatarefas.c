#include <stdio.h>
#include <stdlib.h>
#include "agendatarefas.h"

typedef struct tarefa {
    int prioridade;
    void *tarefa;
    void (*executa)(void*);
    void (*destroi)(void*);
} tTarefa;

struct agendatarefas {
    tTarefa **tarefas;
    int numElem;
    int capacidade;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas *novaAgenda = (tAgendaTarefas*) malloc(sizeof(tAgendaTarefas));
    
    novaAgenda->tarefas = (tTarefa**) malloc(numElem * sizeof(tTarefa*));
    
    novaAgenda->numElem = 0;
    novaAgenda->capacidade = numElem;

    return novaAgenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    
    for (int i = 0; i < tar->numElem; i++) {
        if (tar->tarefas[i]) {
            tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
            free(tar->tarefas[i]);
        }
    }
    
    free(tar->tarefas);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    tTarefa *novaTarefa = (tTarefa*) malloc(sizeof(tTarefa));

    novaTarefa->prioridade = prioridade;
    novaTarefa->tarefa = tarefa;
    novaTarefa->executa = executa;
    novaTarefa->destroi = destroi;

    // Inserir a tarefa no vetor de forma ordenada por prioridade (maior para menor)
    int i = tar->numElem - 1;
    while (i >= 0 && tar->tarefas[i]->prioridade < prioridade) {
        tar->tarefas[i + 1] = tar->tarefas[i];
        i--;
    }
    tar->tarefas[i + 1] = novaTarefa;
    tar->numElem++;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {

    for (int i = 0; i < tar->numElem; i++) {
        tar->tarefas[i]->executa(tar->tarefas[i]->tarefa);
        tar->tarefas[i]->destroi(tar->tarefas[i]->tarefa);
        free(tar->tarefas[i]);
    }
    
    tar->numElem = 0; // Todas as tarefas foram executadas e destruídas
}
