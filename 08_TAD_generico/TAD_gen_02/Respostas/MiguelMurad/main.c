#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>


int main () {
    int tipo, qtd, ind;

    tGerenciador *g = CriaGerenciador();

    while (1) {
        int comando;
        printf("Escolha uma opcao:\n    (1) Cadastrar um novo pacote\n    (2) Imprimir um pacote específico\n    (3) Imprimir todos os pacotes e sair\n");

        scanf("%d", &comando);
        printf("\nCOM: %d\n", comando);
        while (getchar() != '\n'); // Limpa o buffer de entrada

        if (comando == 1) {
            
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:\n");
            scanf("%d %d\n", &tipo, &qtd);

            tPacote *p = CriaPacote(tipo, qtd);
            LePacote(p);
            AdicionaPacoteNoGerenciador(g, p);
            DestroiPacote(p);
        }
            
        if (comando == 2) {
            scanf("%d", &ind);

            ImprimirPacoteNoIndice(g, ind);
        }
            
        if (comando == 3) {
            ImprimirTodosPacotes(g);
            break;
        }

        //getchar();
    }

    DestroiGerenciador(g);

    return 0;
}