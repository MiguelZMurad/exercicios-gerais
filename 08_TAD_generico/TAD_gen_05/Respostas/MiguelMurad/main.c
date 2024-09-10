#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"


int main () {
    int qtd, flag = 0;
    int prioridade;
    char tipoTarefa;
    char msg[60];
    int atualp = 567;
    char atualt = ';';

    printf("Digite o numero de tarefas:");
    scanf("%d", &qtd);

    tAgendaTarefas *t = CriaAgendaDeTarefas(qtd);

    while(qtd) {

        scanf("%d %c", &prioridade, &tipoTarefa);

        if (atualp != prioridade && atualt != tipoTarefa) {
            atualp = prioridade;
            atualt = tipoTarefa;
        
            //printf("\n%d %c\n", prioridade, tipoTarefa);

            if (tipoTarefa == 'I') {

                scanf(" %[^\n]", msg);

                tImpr *tarefaImprimir = CriaTarefaImprimir(msg);
                
                CadastraTarefaNaAgenda(t, prioridade, tarefaImprimir, ExecutaTarefaImprimir, DestroiTarefaImprimir);

            } else if (tipoTarefa == 'S') {
                float n1, n2;

                scanf("%f %f", &n1, &n2);

                tSoma *tarefaSoma = CriaTarefaSoma(n1, n2);
                
                CadastraTarefaNaAgenda(t, prioridade, tarefaSoma, ExecutaTarefaSoma, DestroiTarefaSoma);
                
            } else if (tipoTarefa == 'M') {
                float n1, n2;

                scanf("%f %f", &n1, &n2);

                tMult *tarefaMultiplicar = CriaTarefaMultiplicar(n1, n2);

                CadastraTarefaNaAgenda(t, prioridade, tarefaMultiplicar, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
                
            } else {
    
                printf("\nDigite um tipo de tarefa suportado (I/S/M))\n");
                getchar();
                flag = 1;
            }

            if (flag == 0) {
                qtd--;
            }
            flag = 0;
            //__fpurge(stdin);
        }
    }

    ExecutarTarefasDaAgenda(t);

    DestroiAgendaDeTarefas(t);

    return 0;
}