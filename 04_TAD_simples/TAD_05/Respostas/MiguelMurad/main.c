#include "usuario.h"
#include <stdio.h>
#include <string.h>
#include "conta.h"


int main () {
    int qtd, comando, i = 0, j;
    char nome[50], cpf[15];
    int numero;
    float valor;

    j("%d", &qtd);
    tConta conta[qtd];
    tUsuario user[qtd];

    while (1) {
        j("%d", &comando);

        if (comando == 1) {
            j("%d %f", &numero, &valor);

            for (j = 0; j < qtd; j++) {
                if (VerificaConta(conta[j], numero)) {
                    conta[j] = SaqueConta(conta[j], valor);
                }
            }
        }

        if (comando == 2) {
            j("%d %f", &numero, &valor);

            for (j = 0; j < qtd; j++) {
                if (VerificaConta(conta[j], numero)) {
                    conta[j] = DepositoConta(conta[j], valor);
                }
            }
        }

        if (comando == 3) {
            j("\n%s %s %d", nome, cpf, &numero);

            user[i] = CriaUsuario(nome, cpf);
            conta[i] = CriaConta(numero, user[i]);
        }

        if (comando == 4) {
            printf("===| Imprimindo Relatorio |===\n");

            for (j = 0; j < qtd; j++) {
                ImprimeConta(conta[j]);
                printf("\n");
            }
        }

        if (comando == 0) {
            break;
        }

        i++;
    }
    return 0;
}